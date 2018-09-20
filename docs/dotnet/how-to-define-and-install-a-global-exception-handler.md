---
title: 'Como: definir e instalar um manipulador de exceção Global | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- handlers, global
ms.assetid: dd88a812-3bc7-4ce8-8283-4b674c246534
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ff91a742b1a6641fbc689968587f0472c333e16a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423347"
---
# <a name="how-to-define-and-install-a-global-exception-handler"></a>Como definir e instalar um identificador de exceção global

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

[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)