---
title: "Como implementar uma arquitetura de componente de plug-in usando a reflex&#227;o (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "plug-ins [C++]"
  - "reflexão [C++], plug-ins"
ms.assetid: 4f31e42b-78d1-48b9-8fdc-f28c75e8e77e
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como implementar uma arquitetura de componente de plug-in usando a reflex&#227;o (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os exemplos de código a seguir demonstra o uso de reflexão implementar uma arquitetura de plug\-in “” simples.  A primeira listagem é o aplicativo, e a segunda é o plug\-in.  O aplicativo é mais um formato de documento que se popula que usa qualquer classe baseada em formulários localizadas na DLL de plug\-in fornecido como um argumento de linha de comando.  
  
 O aplicativo tentar carregar o assembly fornece que usa o método de <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> .  Se tiver êxito, os tipos do assembly são enumerados usando o método de <xref:System.Reflection.Assembly.GetTypes%2A?displayProperty=fullName> .  Cada tipo é verificado em para verificar se há compatibilidade usando o método de <xref:System.Type.IsAssignableFrom%2A?displayProperty=fullName> .  Neste exemplo, as classes localizadas no assembly fornece devem ser derivadas da classe de <xref:System.Windows.Forms.Form> para qualificar como um plug\-in.  
  
 As classes correspondentes são criadas uma instância com o método de <xref:System.Activator.CreateInstance%2A?displayProperty=fullName> , que aceita <xref:System.Type> como um argumento e retorna um ponteiro para uma nova instância do.  Cada nova instância em é anexada ao formulário e exibida.  
  
 Observe que o método de <xref:System.Reflection.Assembly.Load%2A> não aceita os nomes do assembly que incluem a extensão de arquivo.  A função principal no aplicativo corta alguns fornecidas extensões, assim os seguintes trabalhos do exemplo de código em ambos os casos.  
  
## Exemplo  
 O código a seguir define o aplicativo que aceita plug\-ins.  Um nome do assembly deve ser fornecida como o primeiro argumento.  Esse assembly deve conter pelo menos um tipo derivado <xref:System.Windows.Forms.Form> do utilitário.  
  
```  
// plugin_application.cpp  
// compile with: /clr /c  
#using <system.dll>  
#using <system.drawing.dll>  
#using <system.windows.forms.dll>  
  
using namespace System;  
using namespace System::Windows::Forms;  
using namespace System::Reflection;  
  
ref class PluggableForm : public Form  {  
public:  
   PluggableForm() {}  
   PluggableForm(Assembly^ plugAssembly) {  
      Text = "plug-in example";  
      Size = Drawing::Size(400, 400);  
      IsMdiContainer = true;  
  
      array<Type^>^ types = plugAssembly->GetTypes( );  
      Type^ formType = Form::typeid;  
  
      for (int i = 0 ; i < types->Length ; i++) {  
         if (formType->IsAssignableFrom(types[i])) {  
            // Create an instance given the type description.  
            Form^ f = dynamic_cast<Form^> (Activator::CreateInstance(types[i]));  
            if (f) {  
               f->Text = types[i]->ToString();  
               f->MdiParent = this;  
               f->Show();  
            }  
         }  
      }  
   }  
};  
  
int main() {  
   Assembly^ a = Assembly::LoadFrom("plugin_application.exe");  
   Application::Run(gcnew PluggableForm(a));  
}  
```  
  
## Exemplo  
 O código a seguir define três classes derivadas de <xref:System.Windows.Forms.Form>.  Quando o nome do nome do assembly resultante é transmitido ao executável na lista anterior, cada uma dessas três classes descoberta e será criada uma instância, independentemente do fato de que eram tudo desconhecidos ao aplicativo host em tempo de compilação.  
  
```  
// plugin_assembly.cpp  
// compile with: /clr /LD  
#using <system.dll>  
#using <system.drawing.dll>  
#using <system.windows.forms.dll>  
  
using namespace System;  
using namespace System::Windows::Forms;  
using namespace System::Reflection;  
using namespace System::Drawing;  
  
public ref class BlueForm : public Form {  
public:  
   BlueForm() {  
      BackColor = Color::Blue;  
   }  
};  
  
public ref class CircleForm : public Form {  
protected:  
   virtual void OnPaint(PaintEventArgs^ args) override {  
      args->Graphics->FillEllipse(Brushes::Green, ClientRectangle);  
   }  
};  
  
public ref class StarburstForm : public Form {  
public:  
   StarburstForm(){  
      BackColor = Color::Black;  
   }  
protected:  
   virtual void OnPaint(PaintEventArgs^ args) override {  
      Pen^ p = gcnew Pen(Color::Red, 2);  
      Random^ r = gcnew Random( );  
      Int32 w = ClientSize.Width;  
      Int32 h = ClientSize.Height;  
      for (int i=0; i<100; i++) {  
         float x1 = w / 2;  
         float y1 = h / 2;  
         float x2 = r->Next(w);  
         float y2 = r->Next(h);  
         args->Graphics->DrawLine(p, x1, y1, x2, y2);  
      }  
   }  
};  
```  
  
## Consulte também  
 [Reflexão](../dotnet/reflection-cpp-cli.md)