---
title: Classes de caixa de diálogo comuns
ms.date: 11/04/2016
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
ms.openlocfilehash: 2efe095a6d5b71321cbbe56fdee662509baa4573
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619030"
---
# <a name="common-dialog-classes"></a>Classes de caixa de diálogo comuns

Além da classe [CDialog](reference/cdialog-class.md), o MFC fornece várias classes derivadas de `CDialog` que encapsulam caixas de diálogo usadas com frequência, conforme mostrado na tabela a seguir. As caixas de diálogo encapsuladas são chamadas de "caixas de diálogo comuns" e fazem parte da biblioteca de caixa de diálogo comum do Windows (COMMDLG. DLL). Os recursos de modelo de caixa de diálogo e o código para essas classes são fornecidos nas caixas de diálogo comuns do Windows que fazem parte do Windows versões 3,1 e posteriores.

### <a name="common-dialog-classes"></a>Classes de caixa de diálogo comuns

|Classe de caixa de diálogo derivada|Finalidade|
|--------------------------|-------------|
|[CColorDialog](reference/ccolordialog-class.md)|Permite que o usuário Selecione cores.|
|[CFileDialog](reference/cfiledialog-class.md)|Permite que o usuário selecione um nome de arquivo para abrir ou salvar.|
|[CFindReplaceDialog](reference/cfindreplacedialog-class.md)|Permite que o usuário inicie uma operação Localizar ou substituir em um arquivo de texto.|
|[CFontDialog](reference/cfontdialog-class.md)|Permite que o usuário especifique uma fonte.|
|[CPrintDialog](reference/cprintdialog-class.md)|Permite que o usuário especifique informações para um trabalho de impressão.|
|[CPrintDialogEx](reference/cprintdialogex-class.md)|Folha de propriedades de impressão do Windows.|

Para obter mais informações sobre as classes de diálogo comuns, consulte os nomes de classe individuais na *referência do MFC*. O MFC também fornece um número de classes de diálogo padrão usadas para OLE. Para obter informações sobre essas classes, consulte a classe base, [COleDialog](reference/coledialog-class.md), na *referência do MFC*.

Três outras classes no MFC têm características semelhantes a caixas de diálogo. Para obter informações sobre classes [CFormView](reference/cformview-class.md), [CRecordView](reference/crecordview-class.md)e [CDaoRecordView](reference/cdaorecordview-class.md), consulte as classes na *referência do MFC*. Para obter informações sobre a classe [CDialogBar](reference/cdialogbar-class.md), consulte [barras de diálogo](dialog-bars.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)<br/>
[Caixas de diálogo em OLE](dialog-boxes-in-ole.md)
