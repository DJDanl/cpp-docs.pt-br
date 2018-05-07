---
title: 'Como: coletor de eventos do Windows Forms de Classes C++ nativas | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- event handling, managed/native interop
- event handling, sinking .NET in C++
- event handling, .NET/native interop
- event handling, Windows Forms in C++
ms.assetid: 6e30ddee-d058-4c8d-9956-2a43d86f19d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0fec32bf179424b5ec0164e4511f74eae44f7320
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-sink-windows-forms-events-from-native-c-classes"></a>Como coletar eventos dos Windows Forms a partir de classes C++ nativas
Você pode habilitar as classes C++ nativo receber retornos de chamada de gerenciado eventos gerados a partir de outros formulários com o formato de mapa de macro MFC ou controles de formulários do Windows. Recebendo eventos em exibições e caixas de diálogo é similar ao fazer a mesma tarefa para controles.  
  
 Para fazer isso, você precisa:  
  
-   Anexar um `OnClick` manipulador de eventos para o controle usando [MAKE_DELEGATE](../mfc/reference/delegate-and-interface-maps.md#make_delegate).  
  
-   Criar um mapa de delegado usando [BEGIN_DELEGATE_MAP](../mfc/reference/delegate-and-interface-maps.md#begin_delegate_map), [END_DELEGATE_MAP](../mfc/reference/delegate-and-interface-maps.md#end_delegate_map), e [EVENT_DELEGATE_ENTRY](../mfc/reference/delegate-and-interface-maps.md#event_delegate_entry).  
  
 Este exemplo continua o trabalho feito em [como: fazer o associação de dados do DDX/DDV aos Windows Forms](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md).  
  
 Agora, você associará seu controle MFC (`m_MyControl`) com um representante do manipulador de eventos gerenciado chamado `OnClick` para gerenciada <xref:System.Windows.Forms.Control.Click> eventos.  
  
### <a name="to-attach-the-onclick-event-handler"></a>Para anexar o manipulador de eventos OnClick:  
  
1.  Adicione o seguinte código para a implementação de BOOL CMFC01Dlg::OnInitDialog:  
  
    ```  
    m_MyControl.GetControl()->button1->Click += MAKE_DELEGATE( System::EventHandler, OnClick );  
    ```  
  
2.  Adicione o seguinte código para a seção pública na declaração da classe CMFC01Dlg: CDialog pública.  
  
    ```  
    // delegate map  
    BEGIN_DELEGATE_MAP( CMFC01Dlg )  
    EVENT_DELEGATE_ENTRY( OnClick, System::Object^, System::EventArgs^ )  
    END_DELEGATE_MAP()  
  
    void OnClick( System::Object^ sender, System::EventArgs^ e );  
    ```  
  
3.  Finalmente, adicione a implementação para `OnClick` para CMFC01Dlg.cpp:  
  
    ```  
    void CMFC01Dlg::OnClick(System::Object^ sender, System::EventArgs^ e)  
    {  
        AfxMessageBox(_T("Button clicked"));  
    }  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [MAKE_DELEGATE](../mfc/reference/delegate-and-interface-maps.md#make_delegate)   
 [BEGIN_DELEGATE_MAP](../mfc/reference/delegate-and-interface-maps.md#begin_delegate_map)   
 [END_DELEGATE_MAP](../mfc/reference/delegate-and-interface-maps.md#end_delegate_map)   
 [EVENT_DELEGATE_ENTRY](../mfc/reference/delegate-and-interface-maps.md#event_delegate_entry)