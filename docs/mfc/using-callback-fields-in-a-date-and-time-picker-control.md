---
title: "Usando campos de retorno de chamada em um controle de seletor de data e hora | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "DTN_FORMATQUERY"
  - "DTN_FORMAT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "campos de retorno de chamada na classe CDateTimeCtrl"
  - "Classe CDateTimeCtrl, campos de retorno de chamada"
  - "Classe CDateTimeCtrl, tratando DTN_FORMAT e DTN_FORMATQ"
  - "Controle DateTimePicker [MFC]"
  - "Controle DateTimePicker [MFC], campos de retorno de chamada"
  - "DTN_FORMAT (notificação)"
  - "DTN_FORMATQUERY (notificação)"
ms.assetid: 404f4ba9-cba7-4718-9faa-bc6b274a723f
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando campos de retorno de chamada em um controle de seletor de data e hora
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além dos caracteres de formato padrão que definem campos de seletor de data e hora, você pode personalizar sua saída especificando algumas partes de uma cadeia de caracteres de formato personalizada como campos de retorno de chamada.  Para declarar um campo de retorno de chamada, contém um ou mais caracteres de “X” \(88\) código ASCII em qualquer lugar no corpo da cadeia de caracteres de formato.  Por exemplo, a seguinte cadeia de caracteres “é “hoje: ” “aa\/” mm “\/“dd” \(dia “X "\)” “faz com que o controle de seletor de data e hora exibe o valor atual como o ano seguido por mês, a data e, finalmente o dia do ano.  
  
> [!NOTE]
>  O número de x em um campo de retorno de chamada não corresponde ao número de caracteres que serão exibidos.  
  
 Você pode distinguir entre vários campos de retorno de chamada em uma cadeia de caracteres personalizado repetindo o caractere “X”.  Assim, a cadeia de caracteres de formato “XXddddMMMdd, 'yyyXXX” contém dois campos exclusivos de retorno de chamada, “XX” e “XXX”.  
  
> [!NOTE]
>  Os campos de retorno de chamada são tratados como campos válidos, de modo que o aplicativo deve estar preparado para tratar notificações de **DTN\_WMKEYDOWN** .  
  
 Implementar campos de retorno de chamada no controle de seletor de data e hora consiste em três partes:  
  
-   Inicializando a cadeia de caracteres de formato personalizada  
  
-   Tratando a notificação de **DTN\_FORMATQUERY**  
  
-   Tratando a notificação de **DTN\_FORMAT**  
  
## Inicializando a cadeia de caracteres de formato personalizada  
 Inicializar a cadeia de caracteres personalizado com uma chamada a `CDateTimeCtrl::SetFormat`.  Para obter mais informações, consulte [Usando cadeias de caracteres de formato personalizadas em um controle de seletor de data e hora](../mfc/using-custom-format-strings-in-a-date-and-time-picker-control.md).  Um local comum para definir a cadeia de caracteres de formato personalizada está na função de `OnInitDialog` da sua classe da caixa de diálogo ou função contentora de `OnInitialUpdate` da sua classe de que contém a exibição.  
  
## Tratando a notificação de DTN\_FORMATQUERY  
 Quando o controle analisa a cadeia de caracteres de formato e localize um campo de retorno de chamada, o aplicativo envia notificações de **DTN\_FORMAT** e de **DTN\_FORMATQUERY** .  A cadeia de caracteres de campo de retorno de chamada é incluída com as notificações para que você possa determinar qual campo de retorno de chamada está sendo consultado.  
  
 A notificação de **DTN\_FORMATQUERY** é enviada para recuperar o tamanho máximo permitido em pixels de cadeia de caracteres que será exibida no campo atual de retorno de chamada.  
  
 Para calcular corretamente esse valor, você deve calcular a altura e a largura da cadeia de caracteres, a ser substituído para o campo, usando a fonte da exibição do controle.  O cálculo real da cadeia de caracteres é obtida facilmente com uma chamada à função de [GetTextExtentPoint32](http://msdn.microsoft.com/library/windows/desktop/dd144938) o Win32.  Uma vez que o tamanho é determinado, passa o valor de volta ao aplicativo e sair da função do manipulador.  
  
 O exemplo a seguir é um método de fornecer o tamanho da cadeia de caracteres de retorno de chamada:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#8](../mfc/codesnippet/CPP/using-callback-fields-in-a-date-and-time-picker-control_1.cpp)]  
  
 O tamanho do campo atual de retorno de chamada é calculada uma vez, você deve fornecer um valor para o campo.  Isso é feito no manipulador para a notificação de **DTN\_FORMAT** .  
  
## Tratando a notificação de DTN\_FORMAT  
 A notificação de **DTN\_FORMAT** é usada pelo aplicativo solicitar a cadeia de caracteres que será preterida.  O exemplo a seguir demonstra um método possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#9](../mfc/codesnippet/CPP/using-callback-fields-in-a-date-and-time-picker-control_2.cpp)]  
  
> [!NOTE]
>  O ponteiro para a estrutura de **NMDATETIMEFORMAT** for localizado convertendo o primeiro parâmetro do manipulador de notificação para o tipo correto.  
  
## Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)