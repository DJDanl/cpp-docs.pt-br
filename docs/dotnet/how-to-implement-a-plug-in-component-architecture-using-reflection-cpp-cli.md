---
title: Implementar uma arquitetura de plug-in (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- plug-ins [C++]
- reflection [C++}, plug-ins
ms.assetid: 4f31e42b-78d1-48b9-8fdc-f28c75e8e77e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4e001ef88af0727a994c309d45167787d3e6677b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33135207"
---
# <a name="how-to-implement-a-plug-in-component-architecture-using-reflection-ccli"></a>Como implementar uma arquitetura de componente de plug-in usando a reflexão (C++/CLI)
Os exemplos de código a seguir demonstram o uso da reflexão para implementar uma arquitetura simples de "plug-in". A primeira listagem é o aplicativo e o segundo é o plug-in. O aplicativo é um formulário de documento vários que preenche usando as classes com base em formulário encontradas na DLL do plug-in fornecido como um argumento de linha de comando.  
  
 O aplicativo tenta carregar o assembly fornecido usando o <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> método. Se for bem-sucedida, os tipos no assembly são enumerados usando o <xref:System.Reflection.Assembly.GetTypes%2A?displayProperty=fullName> método. Em seguida, é verificado a cada tipo de compatibilidade usando o <xref:System.Type.IsAssignableFrom%2A?displayProperty=fullName> método. Neste exemplo, classes encontrados no assembly fornecido devem ser derivados do <xref:System.Windows.Forms.Form> classe para qualificar um plug-in.  
  
 Em seguida, são criadas instâncias de classes compatíveis com o <xref:System.Activator.CreateInstance%2A?displayProperty=fullName> método, que aceita um <xref:System.Type> como um argumento e retorna um ponteiro para uma nova instância. Cada nova instância é anexada ao formulário e exibida.  
  
 Observe que o <xref:System.Reflection.Assembly.Load%2A> método não aceita nomes de assembly que incluem a extensão de arquivo. A função principal do aplicativo corta extensões fornecidos, portanto o exemplo de código a seguir funciona em ambos os casos.  
  
## <a name="example"></a>Exemplo  
 O código a seguir define o aplicativo que aceita os plug-ins. Um nome de assembly deve ser fornecido como o primeiro argumento. Este assembly deve conter pelo menos um público <xref:System.Windows.Forms.Form> tipo derivado.  
  
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
  
## <a name="example"></a>Exemplo  
 O código a seguir define três classes derivadas de <xref:System.Windows.Forms.Form>. Quando o nome do assembly resultante é passado para o executável na lista anterior, cada uma dessas três classes será descoberta e instanciada, apesar do fato de que eles foram todos desconhecidos para o aplicativo de hospedagem em tempo de compilação.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)