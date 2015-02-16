自学Android 遇到个问题 不懂问题出在哪里 求帮忙看看 下边贴出代码
http://www.oschina.net/question/2308884_223379

package com.example.activity_02;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
 
 private EditText factorOne;
 private EditText factorTwo;
 private TextView symbol;
 private Button calculate;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
  super.onCreate(savedInstanceState);
  setContentView(R.layout.activity_main);
  //根据控件的ID 取得代表控件的对象
  factorOne = (EditText) findViewById(R.id.factorOne);
  factorTwo = (EditText) findViewById(R.id.factorTwo);
  symbol = (TextView) findViewById(R.id.symbol);
  calculate = (Button) findViewById(R.id.calculate);
  //为symbol 和calculate 设置显示的值
  //symbol.setText("乘以");
  //calculate.setText("计算");
  symbol.setText(R.string.symbol);
  calculate.setText(R.string.calculate);
  //将监听器的对象绑定到按钮的对象上面
  calculate.setOnClickListener(new CalculateListener());
 }
 class CalculateListener implements OnClickListener{

  @Override
  public void onClick(View v) {
   //取得两个EditText控件的值
   String factorOneStr = factorOne.getText().toString();
   String factorTwoStr = factorTwo.getText().toString();
   //将两个值存放到intent对象当中
   Intent intent = new Intent();
   intent.putExtra("one", factorOneStr);
   intent.putExtra("two", factorTwoStr);
   intent.setClass(MainActivity.this, ResultActivity.class);
   //使用这个intent对象启动ResultActivity
   MainActivity.this.startActivity(intent);
  }
  
 }

 
}


package com.example.activity_02;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;
//接收从mainactivity当中所传递的值
//计算两个值得积
//将计算的结果显示在Activity里

public class ResultActivity extends Activity{
 private TextView resultView;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
  // TODO Auto-generated method stub
  super.onCreate(savedInstanceState);
  setContentView(R.layout.result);
  resultView = (TextView) findViewById(R.id.result);
  Intent intent = getIntent();
  String factorOneStr = intent.getStringExtra("one");
  String factorTwoStr = intent.getStringExtra("two");
  int factorOneInt = Integer.parseInt(factorOneStr);
  int factorTwoInt = Integer.parseInt(factorTwoStr);
  int result = factorOneInt * factorTwoInt;
  resultView.setText(result + "");
 }

}



<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:orientation="vertical"
    android:layout_width="fill_parent"
    android:layout_height="fill_parent"
    >
 
    <EidtText
        android:id="@+id/factorOne"
        android:layout_width="fill_parent"
        android:layout_height="wrap_content"
        />
    <TextView
        android:id="@+id/symbol"
        android:layout_width="fill_parent"
        android:layout_height="wrap_content" 
        />
    <EidtText
        android:id="@+id/factorTwo"
        android:layout_width="fill_parent"
        android:layout_height="wrap_content"
        />
    <Button 
        android:id="@+id/calculate"
        android:layout_width="fill_parent"
        android:layout_height="wrap_content"
        />
   

</LinearLayout>


<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context="com.example.activity_02.MainActivity" >
 
    <TextView 
        android:id="@+id/result"
        android:layout_width="fill_parent"
        android:layout_height="wrap_content"/>
   

</LinearLayout>