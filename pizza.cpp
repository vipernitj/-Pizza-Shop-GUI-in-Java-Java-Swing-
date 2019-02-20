package pizzaShop;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class PizzaShop extends JFrame{

	//elements declaration
	JLabel upText, topping, pizzaSize, pizzaType, message;
	JLabel orderDetail;
	JCheckBox tomato, greenPepper, blackOlives, mushroom,extraCheese, pepproni, sausage ;
	JRadioButton small, medium, large, thinCrust, mediumCrust, pan;
	ButtonGroup sizeGroup, typeGroup;
	JButton processSelection;
	JPanel toppingPanel, sizePanel, typePanel;
    int toppingCount = 0;
    float pizzaSizePrice = 0;

	//constructor for sending the name to parent class
	private PizzaShop(String s)
	{
		super(s); 
	}

	public static void main(String[] args) {

		PizzaShop pizzaShop = new PizzaShop("Pizza Shop");
		
		pizzaShop.setComponent();
		
		pizzaShop.setSize(500, 470);
		pizzaShop.setVisible(true);
		pizzaShop.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	private void setComponent() {

        orderDetail = new JLabel();
        upText = new JLabel("Welcome to Home Style Pizza Shop");
        topping = new JLabel("Each Topping $1.50");
        pizzaSize = new JLabel("Pizza Size");
        pizzaType = new JLabel("Pizza Type");
        tomato = new JCheckBox("Tomato");
        greenPepper = new JCheckBox("Green Pepper");
        blackOlives = new JCheckBox("Black Olives");
        mushroom = new JCheckBox("Mushroom");
        extraCheese = new JCheckBox("Extra Cheese");
        pepproni = new JCheckBox("Pepproni");
        sausage = new JCheckBox("Sausage");
        small = new JRadioButton("Small: $6.50");
        medium = new JRadioButton("Medium: $8.50");
        large = new JRadioButton("Large: $10.0");
        thinCrust = new JRadioButton("Thin Crust");
        mediumCrust = new JRadioButton("Medium Crust");
        pan = new JRadioButton("Pan");
        message = new JLabel("Your Order:");
        toppingPanel = new JPanel();
        sizePanel = new JPanel();
        typePanel = new JPanel();
        sizeGroup = new ButtonGroup();
        typeGroup = new ButtonGroup();
        processSelection = new JButton("Process Selection");

        toppingPanel.setBorder(BorderFactory.createLineBorder(Color.black));
        sizePanel.setBorder(BorderFactory.createLineBorder(Color.black));
        typePanel.setBorder(BorderFactory.createLineBorder(Color.black));

        upText.setForeground(Color.RED);
        topping.setForeground(Color.RED);
        pizzaSize.setForeground(Color.RED);
        pizzaType.setForeground(Color.RED);

        setLayout(null);
        upText.setBounds(125, 20, 400, 50);
        topping.setBounds(50, 70, 200, 20);
        pizzaSize.setBounds(200, 70, 150, 20);
        pizzaType.setBounds(350, 70, 150, 20);
        tomato.setBounds(60, 100, 150, 20);
        greenPepper.setBounds(60, 130, 150, 20);
        blackOlives.setBounds(60, 160, 150, 20);
        mushroom.setBounds(60, 190, 150, 20);
        extraCheese.setBounds(60, 220, 150, 20);
        pepproni.setBounds(60, 250, 120, 20);
        sausage.setBounds(60, 280, 120, 20);
        small.setBounds(210, 100, 150, 20);
        medium.setBounds(210, 160, 150, 20);
        large.setBounds(210, 220, 150, 20);
        thinCrust.setBounds(360, 100, 150, 20);
        mediumCrust.setBounds(360, 160, 150, 20);
        pan.setBounds(360, 220, 150, 20);
        processSelection.setBounds(200, 260, 250, 40);
        message.setBounds(60, 320, 150, 20);
        orderDetail.setBounds(60, 320, 450, 100);

        //adding size radiobutton to a single group
        sizeGroup.add(small);
        sizeGroup.add(medium);
        sizeGroup.add(large);

        //adding type radio to single group
        typeGroup.add(thinCrust);
        typeGroup.add(mediumCrust);
        typeGroup.add(pan);

        toppingPanel.add(tomato);
        toppingPanel.add(greenPepper);
        toppingPanel.add(blackOlives);
        toppingPanel.add(mushroom);
        toppingPanel.add(extraCheese);
        toppingPanel.add(pepproni);
        toppingPanel.add(sausage);
        toppingPanel.setVisible(true);
        toppingPanel.setBackground(Color.RED);

        //add elements to panel
        sizePanel.add(pizzaSize);
        sizePanel.add(small);
        sizePanel.add(medium);
        sizePanel.add(large);
        sizePanel.setVisible(true);
        sizePanel.setBackground(Color.RED);


        //add elements to panel
        typePanel.add(pizzaType);
        typePanel.add(thinCrust);
        typePanel.add(mediumCrust);
        typePanel.add(pan);
        typePanel.setVisible(true);
        typePanel.setBackground(Color.RED);


        //adding components to frame
        add(upText);
        add(topping);
        add(pizzaSize);
        add(pizzaType);
        add(tomato);
        add(greenPepper);
        add(blackOlives);
        add(mushroom);
        add(extraCheese);
        add(pepproni);
        add(sausage);
        add(small);
        add(medium);
        add(large);
        add(thinCrust);
        add(mediumCrust);
        add(pan);
        add(toppingPanel);
        add(sizePanel);
        add(typePanel);
        add(processSelection);
        add(message);
        add(orderDetail);

        //button clicked action listener
		processSelection.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                orderDetail.setText("<html>Pizza Type: " + pizzaType() + "<br/>Pizza Size: " + pizzaSize() + "<br/>Toppings: " + toppingsSelected() + "<br/>Amount Due: $" + totalAmount(toppingCount, pizzaSizePrice) +  "</html>");
            }
        });


	}

	//type of pizza
	private String pizzaType(){
	    if(thinCrust.isSelected())
	        return thinCrust.getText();
	    else if(mediumCrust.isSelected())
	        return mediumCrust.getText();
	    else if(pan.isSelected())
	        return pan.getText();

	    return "";
    }

	//method for pizza size
	private String pizzaSize() {
        if(small.isSelected()) {
            pizzaSizePrice = 6.5f;
            return "Small";
        }
        else if(medium.isSelected()) {
            pizzaSizePrice = 8.5f;
            return "Medium";
        }
        else if(large.isSelected()){
            pizzaSizePrice = 10.0f;
            return "Large";
        }
        return "";
    }

	//method for topping selection
	private String toppingsSelected(){
	    String toppings = "";
	    if(tomato.isSelected()) {
            toppings += "Tomato,";
            toppingCount++;
        }
        if(greenPepper.isSelected()) {
            toppings += " Green Pepper,";
            toppingCount++;
        }
        if(blackOlives.isSelected()) {
            toppings += " Black Olives,";
            toppingCount++;
        }
        if(mushroom.isSelected()) {
            toppings += " Mushroom,";
            toppingCount++;
        }
        if(extraCheese.isSelected()) {
            toppings += " Extra Cheese,";
            toppingCount++;
        }
        if(pepproni.isSelected()) {
            toppings += " Pepproni,";
            toppingCount++;
        }
        if(sausage.isSelected()) {
            toppings += " Sausage,";
            toppingCount++;
        }
        return toppings;
    }

	//method to calculate price of the order
    private float totalAmount(int toppingCount, float pizzaSize){
        return (float) (toppingCount * 1.5 + pizzaSize);
    }
}
