---
title: "Macros e globais MFC | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "convenção de nomenclatura Afx"
  - "funções globais"
  - "funções globais, MFC"
  - "variáveis globais, MFC"
  - "Macros "
  - "Macros , MFC"
  - "MFC, funções globais e variáveis"
  - "MFC, Macros "
ms.assetid: add4e33f-0e62-4d27-be14-896cb8675d22
caps.latest.revision: 18
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros e globais MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classes do Microsoft pode ser dividida em duas seções principais: \(1\) as classes de MFC e \(2\) macros e globais.  Se uma função ou variável não é um membro de uma classe, é uma função ou variável global.  
  
 A biblioteca MFC e a biblioteca ativa \(ATL\) do modelo compartilham macros de conversão de cadeia de caracteres.  Para obter mais informações, consulte [Macros de conversão de cadeia de caracteres](../../atl/reference/string-conversion-macros.md) na documentação de ATL.  
  
 Macros e os globais MFC oferecem funcionalidades nas seguintes categorias.  
  
## MFC geral  
  
-   [Tipos de dados](../Topic/Data%20Types%20\(MFC\).md)  
  
-   [Conversão de tipos de objetos da classe de MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md)  
  
-   [Serviços do modelo de objeto de tempo de execução](../../mfc/reference/run-time-object-model-services.md)  
  
-   [Serviços de diagnóstico](../Topic/Diagnostic%20Services.md)  
  
-   [Processamento de exceção](../../mfc/reference/exception-processing.md)  
  
-   [Formatação de CString e exibição da caixa de mensagem](../../mfc/reference/cstring-formatting-and-message-box-display.md)  
  
-   [Mapas da mensagem](../../mfc/reference/message-map-macros-mfc.md)  
  
-   [Informações e gerenciamento de aplicativo](../Topic/Application%20Information%20and%20Management.md)  
  
-   [IDs padrão de comando e a janela](../../mfc/reference/standard-command-and-window-ids.md)  
  
-   [Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)  
  
-   [Funções em cinza e hesitadas de bitmap](../../mfc/reference/gray-and-dithered-bitmap-functions.md)  
  
-   [Rotinas de troca de dados da caixa de diálogo padrão \(DDX\)](../Topic/Standard%20Dialog%20Data%20Exchange%20Routines.md)  
  
-   [Rotinas padrão de \(DDV\) de validação de dados na caixa de diálogo](../../mfc/reference/standard-dialog-data-validation-routines.md)  
  
-   [Mensagens AFX](../../mfc/reference/afx-messages.md)  
  
-   [Estilos de controle da ToolBar](../Topic/ToolBar%20Control%20Styles.md)  
  
-   [Enumeração CMFCImagePaintArea::IMAGE\_EDIT\_MODE](../Topic/CMFCImagePaintArea::IMAGE_EDIT_MODE%20Enumeration.md)  
  
## Banco de dados  
  
-   [Funções do Exchange do campo de registro \(RFX\)](../../mfc/reference/record-field-exchange-functions.md) e [Funções em massa do Exchange do campo de registro \(RFX em massa\)](../../mfc/reference/record-field-exchange-functions.md) para o ODBC classificam MFC  
  
-   [Funções de troca do campo de registro \(DFX\)](../../mfc/reference/record-field-exchange-functions.md) para classes de MFC DAO  
  
-   [A caixa de diálogo de troca de dados \(DDX\) serve para CRecordView e CDaoRecordView](../../mfc/reference/dialog-data-exchange-functions-for-crecordview-and-cdaorecordview.md) classes \(MFC ODBC e de DAO\)  
  
-   [A caixa de diálogo de troca de dados \(DDX\) serve para controladores OLE](../../mfc/reference/dialog-data-exchange-functions-for-ole-controls.md)  
  
-   [Macros e globais para ajudar em funções de API do ODBC de chamada diretamente \(ODBC\)](../../mfc/reference/database-macros-and-globals.md)  
  
-   [Inicialização e término do mecanismo de base de dados de DAO](../../mfc/reference/dao-database-engine-initialization-and-termination.md)  
  
## Internet  
  
-   [Globais de análise da URL da Internet](../Topic/Internet%20URL%20Parsing%20Globals.md)  
  
## Mapas de evento do DHTML\/DHTML  
  
-   [Macros de troca de dados auxiliar da caixa de diálogo do DHTML \(DDX\)](../../mfc/reference/ddx-dhtml-helper-macros.md)  
  
-   [Mapas de evento do DHTML](../../mfc/reference/dhtml-event-maps.md)  
  
## OLE  
  
-   [Inicialização OLE](../../mfc/reference/ole-initialization.md)  
  
-   [Controle de aplicativo](../../mfc/reference/application-control.md)  
  
-   [Mapas de distribuição](../../mfc/reference/dispatch-maps.md)  
  
 Além disso, o MFC fornece uma função chamada [AfxEnableControlContainer](../Topic/AfxEnableControlContainer.md) que permite que qualquer contêiner OLE desenvolvido com MFC 4,0 para aceitar completamente controladores OLE inseridos.  
  
## Controles OLE  
  
-   [Constantes variantes do tipo de parâmetro](../Topic/Variant%20Parameter%20Type%20Constants.md)  
  
-   [Acesso da biblioteca de tipos](../../mfc/reference/type-library-access.md)  
  
-   [Páginas de propriedades](../../mfc/reference/property-pages-mfc.md)  
  
-   [Mapas de evento](../../mfc/reference/event-maps.md)  
  
-   [Mapas de coletor de eventos](../../mfc/reference/event-sink-maps.md)  
  
-   [Mapas de conexão](../../mfc/reference/connection-maps.md)  
  
-   [Registrando controladores OLE](../Topic/Registering%20OLE%20Controls.md)  
  
-   [Fábricas e licenciamento da classe](../../mfc/reference/class-factories-and-licensing.md)  
  
-   [Persistência de controladores OLE](../../mfc/reference/persistence-of-ole-controls.md)  
  
 A primeira parte desta seção discute brevemente cada uma das categorias anteriores e lista os globais e macros na categoria, junto com descrições resumidas da funcionalidade do.  Depois disso são as descrições de funções globais, variáveis globais, e de macros na biblioteca MFC.  
  
> [!NOTE]
>  O início global de muitas funções com o prefixo “Afx”, mas alguns, por exemplo, as funções de troca de dados da caixa de diálogo \(DDX\) e muitas das funções de base de dados, não segue esta convenção.  Qualquer início de variáveis globais com “afx” como prefixo.  Macros não iniciam com nenhum prefixo específico, mas são gravados em letras maiúsculas.  
  
## Consulte também  
 [Visão geral da classe](../../mfc/class-library-overview.md)