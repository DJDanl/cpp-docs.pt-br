---
title: Classes de caixa de diálogo comuns | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog classes [MFC]
- dialog boxes [MFC], Windows common dialogs
- common dialog boxes [MFC], common dialog classes
- common dialog classes [MFC]
- MFC dialog boxes [MFC], Windows common dialogs
- Windows common dialogs [MFC]
- dialog classes [MFC], common
- common dialog boxes [MFC]
ms.assetid: 5c4f6443-896c-4b05-a7df-8169fdadc71d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0a937ded9fe356627e36ad0262e749446553aa91
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379717"
---
# <a name="common-dialog-classes"></a>Classes de caixa de diálogo comuns

Além de classe [CDialog](../mfc/reference/cdialog-class.md), MFC fornece várias classes derivadas de `CDialog` que encapsulam as caixas de diálogo comumente usadas, como mostrado na tabela a seguir. As caixas de diálogo encapsuladas são chamadas de "caixas de diálogo comuns" e são parte da biblioteca de caixa de diálogo comuns do Windows (COMMDLG. DLL). Recursos de modelo de caixa de diálogo e o código para essas classes são fornecidos no Windows caixas de diálogo comuns que fazem parte do Windows versões 3.1 e posteriores.

### <a name="common-dialog-classes"></a>Classes de caixa de diálogo comuns

|Classe derivada de caixa de diálogo|Finalidade|
|--------------------------|-------------|
|[CColorDialog](../mfc/reference/ccolordialog-class.md)|Permite que as cores de select do usuário.|
|[CFileDialog](../mfc/reference/cfiledialog-class.md)|Permite que o usuário selecione um nome de arquivo para abrir ou salvar.|
|[CFindReplaceDialog](../mfc/reference/cfindreplacedialog-class.md)|Permite que usuário iniciar uma localização ou operação em um arquivo de texto de substituição.|
|[CFontDialog](../mfc/reference/cfontdialog-class.md)|Permite que o usuário especifique uma fonte.|
|[CPrintDialog](../mfc/reference/cprintdialog-class.md)|Permite que o usuário especifique informações para um trabalho de impressão.|
|[CPrintDialogEx](../mfc/reference/cprintdialogex-class.md)|Folha de propriedades de impressão do Windows.|

Para obter mais informações sobre as classes de caixa de diálogo comuns, consulte os nomes de classe individual na *referência da MFC*. MFC também fornece um número de classes de caixa de diálogo padrão usadas para OLE. Para obter informações sobre essas classes, consulte a classe base, [COleDialog](../mfc/reference/coledialog-class.md), no *referência da MFC*.

Três outras classes no MFC têm as características do tipo de caixa de diálogo. Para obter informações sobre as classes [CFormView](../mfc/reference/cformview-class.md), [CRecordView](../mfc/reference/crecordview-class.md), e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md), consulte as classes a *referência da MFC*. Para obter informações sobre a classe [CDialogBar](../mfc/reference/cdialogbar-class.md), consulte [barras da caixa de diálogo](../mfc/dialog-bars.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Caixas de diálogo em OLE](../mfc/dialog-boxes-in-ole.md)

