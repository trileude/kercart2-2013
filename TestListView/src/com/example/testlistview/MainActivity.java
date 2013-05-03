package com.example.testlistview;

import java.util.ArrayList;
import java.util.List;

import moto.Moto;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.ListView;

public class MainActivity extends Activity {

	List<Moto> items;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
     // Settings data
        items = new ArrayList<Moto>();
        Moto yamaha = new Moto("Yamaha","Japon");
        Moto ducati = new Moto("Ducati","Italie");
        Moto bmw = new Moto("BMW","Allemagne");
        items.add(yamaha);
        items.add(ducati);
        items.add(bmw);
        // Settings ListView
        ListView listOfMotorCycle = FindViewById<ListView>(R.id.listMotorCycle);
        MotoAdapter myAdapter = new MotoAdapter(this,R.layout.Moto,items);
        listOfMotorCycle.Adapter = myAdapter;
        Button btnAdd = FindViewById<Button>(Resource.Id.btnAdd);
        btnAdd.Click+=delegate{
           Moto triumph = new Moto("Triumph","Angleterre");
           myAdapter.Add(triumph);
           myAdapter.NotifyDataSetChanged();
        };
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}



 /* [Activity (Label = "BasicAdapterUsage", MainLauncher = true)]
  public class BasicAdapterUsage : Activity
  {
     


     protected override void OnCreate (Bundle bundle)
     {
        
     }
  }*/
