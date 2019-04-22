---
title: 'Como: Definir e instalar um manipulador de exceção Global'
ms.date: 11/04/2016
helpviewer_keywords:
- handlers, global
ms.assetid: dd88a812-3bc7-4ce8-8283-4b674c246534
ms.openlocfilehash: d1b8452d19172bf16817c36032189accfd855539
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58777201"
---
# <a name="how-to-define-and-install-a-global-exception-handler"></a>Como: Definir e instalar um manipulador de exceção Global

O exemplo de código a seguir demonstra como sem tratamento de exceções podem ser capturadas. O formulário de exemplo contém um botão que, quando pressionadas, executa uma referência nula, causando uma exceção seja lançada. Essa funcionalidade representa uma falha de código típico. A exceção resultante é capturada pelo manipulador de exceção de todo o aplicativo instalado pela função principal.

Isso é realizado pela vinculação de um delegado para o <xref:System.Windows.Forms.Application.ThreadException> eventos. Nesse caso, exceções subsequentes, em seguida, são enviadas para o `App::OnUnhandled` método.

## <a name="example"></a>Exemplo

```
// global_exception_handler.cpp
// compile with: /clr
#using <system.dll>
#using <system.drawing.dll>
#using <system.windows.forms.dll>

using namespace System;
using namespace System::Threading;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class MyForm : public Form
{
   Button^ b;
public:
   MyForm( )
   {
      b = gcnew Button( );
      b->Text = "Do Null Access";
      b->Size = Drawing::Size(150, 30);
      b->Click += gcnew EventHandler(this, &MyForm::OnClick);
      Controls->Add(b);
   }
   void OnClick(Object^ sender, EventArgs^ args)
   {
      // do something illegal, like call through a null pointer...
      Object^ o = nullptr;
      o->ToString( );
   }
};

ref class App
{
public:
   static void OnUnhandled(Object^ sender, ThreadExceptionEventArgs^ e)
   {
      MessageBox::Show(e->Exception->Message, "Global Exeception");
      Application::ExitThread( );
   }
};

int main()
{
   Application::ThreadException += gcnew
      ThreadExceptionEventHandler(App::OnUnhandled);

   MyForm^ form = gcnew MyForm( );
   Application::Run(form);
}
```

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../extensions/exception-handling-cpp-component-extensions.md)
