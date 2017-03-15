---
title: Macros e globais MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- MFC, global functions and variables
- MFC, macros
- global functions, MFC
- macros, MFC
- global functions
- global variables, MFC
- Afx naming convention
- macros
ms.assetid: add4e33f-0e62-4d27-be14-896cb8675d22
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: d26b374e233326ac5acc97486edc8d38e6bf5d81
ms.openlocfilehash: 75db28c7be1ab497ba9656136d22b114b488c4ae
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-macros-and-globals"></a>Macros e globais MFC
A biblioteca Microsoft Foundation Class pode ser dividida em duas seções principais: (1) as classes MFC e (2) macros e globais. Se uma função ou variável não for um membro de uma classe, é uma função global ou variável.  
  
 A biblioteca MFC e a biblioteca ATL (Active Template) compartilham macros de conversão de cadeia de caracteres. Para obter mais informações, consulte [Macros de conversão de cadeia de caracteres](../../atl/reference/string-conversion-macros.md) na documentação do ATL.  
  
 As macros e globais MFC oferecem funcionalidade nas categorias a seguir.  
  
## <a name="general-mfc"></a>MFC geral  
  
-   [Tipos de dados](../../mfc/reference/data-types-mfc.md)  
  
-   [Conversão de tipo de objetos de classe MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md)  
  
-   [Serviços do modelo de objeto de tempo de execução](../../mfc/reference/run-time-object-model-services.md)  
  
-   [Serviços de diagnóstico](../../mfc/reference/diagnostic-services.md)  
  
-   [Processamento de exceção](../../mfc/reference/exception-processing.md)  
  
-   [Formatação CString e exibição da caixa de mensagem](../../mfc/reference/cstring-formatting-and-message-box-display.md)  
  
-   [Mapas de mensagem](../../mfc/reference/message-map-macros-mfc.md)  
  
-   [Gerenciamento e informações do aplicativo](../../mfc/reference/application-information-and-management.md)  
  
-   [IDs de comando e janela padrão](../../mfc/reference/standard-command-and-window-ids.md)  
  
-   [Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)  
  
-   [Funções de bitmap cinza e pontilhado](../../mfc/reference/gray-and-dithered-bitmap-functions.md)  
  
-   [Rotinas de troca (DDX) de dados de caixa de diálogo padrão](../../mfc/reference/standard-dialog-data-exchange-routines.md)  
  
-   [Rotinas de validação (DDV) de dados de caixa de diálogo padrão](../../mfc/reference/standard-dialog-data-validation-routines.md)  
  
-   [Mensagens AFX](../../mfc/reference/afx-messages.md)  
  
-   [Estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md)  
  
-   [Enumeração cmfcimagepaintarea:: Image_edit_mode](cmfcimagepaintarea-image-edit-mode-enumeration.md)  

  
## <a name="database"></a>Banco de Dados  
  
-   [Registrar funções de campo Exchange (RFX)](../../mfc/reference/record-field-exchange-functions.md) e [funções de troca de campos do registro em massa (RFX em massa)](../../mfc/reference/record-field-exchange-functions.md) para as classes MFC ODBC  
  
-   [Registrar funções de troca (DFX) do campo](../../mfc/reference/record-field-exchange-functions.md) para as classes MFC DAO  
  
-   [Funções de troca de dados de caixa de diálogo (DDX) para CRecordView e CDaoRecordView](../../mfc/reference/dialog-data-exchange-functions-for-crecordview-and-cdaorecordview.md) (classes MFC ODBC e DAO)  
  
-   [Funções de exchange (DDX) de dados de caixa de diálogo para controles OLE](../../mfc/reference/dialog-data-exchange-functions-for-ole-controls.md)  
  
-   [Macros e globais para ajudar a chamar funções de conectividade de banco de dados aberto (ODBC) API diretamente](../../mfc/reference/database-macros-and-globals.md)  
  
-   [Encerramento e inicialização do mecanismo de banco de dados DAO](../../mfc/reference/dao-database-engine-initialization-and-termination.md)  
  
## <a name="internet"></a>Internet  
  
-   [URL da Internet globais de análise](../../mfc/reference/internet-url-parsing-globals.md)  
  
## <a name="dhtml--dhtml-event-maps"></a>DHTML / mapas de evento DHTML  
  
-   [Macros de auxiliar (DDX) de troca de dados de caixa de diálogo DHTML](../../mfc/reference/ddx-dhtml-helper-macros.md)  
  
-   [Mapas de evento DHTML](../../mfc/reference/dhtml-event-maps.md)  
  
## <a name="ole"></a>OLE  
  
-   [Inicialização OLE](../../mfc/reference/ole-initialization.md)  
  
-   [Controle do aplicativo](../../mfc/reference/application-control.md)  
  
-   [Mapas de expedição](../../mfc/reference/dispatch-maps.md)  
  
 Além disso, o MFC fornece uma função chamada [AfxEnableControlContainer](http://msdn.microsoft.com/library/7aa0b9d2-5329-4bc3-9d41-856e30fe2c2b) que permite que qualquer contêiner OLE desenvolvido com o MFC 4.0 para dar suporte total inseridos controles OLE.  
  
## <a name="ole-controls"></a>Controles OLE  
  
-   [Constantes de tipo de parâmetro variante](../../mfc/reference/variant-parameter-type-constants.md)  
  
-   [Acesso à biblioteca de tipos](../../mfc/reference/type-library-access.md)  
  
-   [Páginas de propriedade](../../mfc/reference/property-pages-mfc.md)  
  
-   [Mapas de evento](../../mfc/reference/event-maps.md)  
  
-   [Mapas de coleta de eventos](../../mfc/reference/event-sink-maps.md)  
  
-   [Mapas de Conexão](../../mfc/reference/connection-maps.md)  
  
-   [Registrando controles OLE](../../mfc/reference/registering-ole-controls.md)  
  
-   [Fábricas de classe e licenciamento](../../mfc/reference/class-factories-and-licensing.md)  
  
-   [Persistência de controles OLE](../../mfc/reference/persistence-of-ole-controls.md)  
  
 A primeira parte desta seção rapidamente descreve cada uma das categorias anteriores e listas globais e macros na categoria, junto com descrições breves de funcionalidade. Após isso há descrições das funções globais, variáveis globais e macros na biblioteca MFC.  
  
> [!NOTE]
>  Muitas funções globais começam com o prefixo "Afx", mas alguns, por exemplo, as funções de dados de caixa de diálogo (DDX) do exchange e muitas das funções de banco de dados, não seguir essa convenção. Todas as variáveis globais começar com "afx" como um prefixo. As macros não começar com um prefixo específico, mas eles são escritos em letras maiusculas.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../mfc/class-library-overview.md)




