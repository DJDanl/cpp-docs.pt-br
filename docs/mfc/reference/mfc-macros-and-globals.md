---
title: Macros e globais MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, global functions and variables
- MFC, macros
- global functions, MFC
- macros, MFC
- global functions [MFC]
- global variables, MFC
- Afx naming convention
- macros
ms.assetid: add4e33f-0e62-4d27-be14-896cb8675d22
ms.openlocfilehash: ed45fc7014bda18887be6dc8fbcdff8ba9a9c5f1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373052"
---
# <a name="mfc-macros-and-globals"></a>Macros e globais MFC

A Biblioteca de Classes da Microsoft Foundation pode ser dividida em duas seções principais: (1) as classes MFC e (2) macros e globals. Se uma função ou variável não é um membro de uma classe, é uma função ou variável global.

A biblioteca MFC e a Active Template Library (ATL) compartilham macros de conversão de seqüência. Para obter mais informações, consulte [Macros de conversão de strings](../../atl/reference/string-conversion-macros.md) na documentação ATL.

As macros e globais do MFC oferecem funcionalidade nas seguintes categorias.

## <a name="general-mfc"></a>MFC Geral

- [Tipos de dados](data-types-mfc.md)

- [Digite o casting de objetos de classe MFC](type-casting-of-mfc-class-objects.md)

- [Serviços de modelo de objeto em tempo de execução](run-time-object-model-services.md)

- [Serviços de diagnóstico](diagnostic-services.md)

- [Processamento de exceções](exception-processing.md)

- [Formatação CString e exibição da caixa de mensagem](cstring-formatting-and-message-box-display.md)

- [Mapas de mensagens](message-map-macros-mfc.md)

- [Mapas de delegados e interfaces](delegate-and-interface-maps.md)

- [Módulos e DLLs](extension-dll-macros.md)

- [Informações e gerenciamento de aplicativos](application-information-and-management.md)

- [Comando padrão e IDs de janela](standard-command-and-window-ids.md)

- [Ajudantes de classe de coleta](collection-class-helpers.md)

- [Funções de bitmap cinza e dithered](gray-and-dithered-bitmap-functions.md)

- [Rotinas padrão de troca de dados de diálogo (DDX)](standard-dialog-data-exchange-routines.md)

- [Rotinas padrão de validação de dados de diálogo (DDV)](standard-dialog-data-validation-routines.md)

- [Mensagens AFX](afx-messages.md)

- [Estilos de controle da barra de ferramentas](toolbar-control-styles.md)

- [Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md)

## <a name="database"></a>Banco de dados

- [Funções de Record Field Exchange (RFX)](record-field-exchange-functions.md) e [Funções bulk Record Field Exchange (RFX em massa)](record-field-exchange-functions.md) para as classes MFC ODBC

- [Funções de troca de campo de registro (DFX)](record-field-exchange-functions.md) para as classes DaO do MFC

- [Funções de troca de dados de diálogo (DDX) para as classes CRecordView e CDaoRecordView](dialog-data-exchange-functions-for-crecordview-and-cdaorecordview.md) (classes MFC ODBC e DAO)

- [Funções de troca de dados de diálogo (DDX) para controles OLE](dialog-data-exchange-functions-for-ole-controls.md)

- [Macros e globals para ajudar a chamar a API de Conectividade de Banco de Dados Aberto (ODBC) funciona diretamente](database-macros-and-globals.md)

- [Inicialização e terminação do mecanismo de banco de dados DAO](dao-database-engine-initialization-and-termination.md)

## <a name="internet"></a>Internet

- [Globals de análise de URL da Internet](internet-url-parsing-globals.md)

## <a name="dhtml--dhtml-event-maps"></a>Mapas de eventos DHTML / DHTML

- [Macros do helper dHTML de troca de dados de diálogo (DDX)](ddx-dhtml-helper-macros.md)

- [Mapas de eventos DHTML](dhtml-event-maps.md)

## <a name="ole"></a>OLE

- [Inicialização do OLE](ole-initialization.md)

- [Controle de aplicativo](application-control.md)

- [Mapas de despacho](dispatch-maps.md)

Além disso, o MFC fornece uma função chamada [AfxEnableControlContainer](ole-initialization.md#afxenablecontrolcontainer) que permite que qualquer contêiner OLE desenvolvido com MFC 4.0 suporte totalmente aos controles OLE incorporados.

## <a name="ole-controls"></a>Controles OLE

- [Constantes do tipo parâmetro de variante](variant-parameter-type-constants.md)

- [Digite acesso à biblioteca](type-library-access.md)

- [Páginas de propriedades](property-pages-mfc.md)

- [Mapas de eventos](event-maps.md)

- [Mapas de dissipação de eventos](event-sink-maps.md)

- [Mapas de conexão](connection-maps.md)

- [Registrando controles OLE](registering-ole-controls.md)

- [Fábricas de classe e licenciamento](class-factories-and-licensing.md)

- [Persistência dos controles OLE](persistence-of-ole-controls.md)

A primeira parte desta seção discute brevemente cada uma das categorias anteriores e lista os globais e macros da categoria, juntamente com breves descrições de funcionalidade. A seguir estão descrições das funções globais, variáveis globais e macros na biblioteca do MFC.

> [!NOTE]
> Muitas funções globais começam com o prefixo "Afx", mas algumas, por exemplo, as funções de troca de dados de diálogo (DDX) e muitas das funções do banco de dados, não seguem essa convenção. Todas as variáveis globais começam com "afx" como prefixo. As macros não começam com nenhum prefixo específico, mas são escritas em letras maiúsculas.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../mfc/class-library-overview.md)
