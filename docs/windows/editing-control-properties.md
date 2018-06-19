---
title: Editando propriedades de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], undoing changes
- controls [C++], editing properties
- dialog box controls, editing properties
ms.assetid: 9bdae21d-6dec-4344-a197-2ca4fc46d040
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f7976f74e9454b023c4da51168fa780ccaea2342
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873479"
---
# <a name="editing-control-properties"></a>Editando propriedades de controle
### <a name="to-edit-the-properties-of-a-control-or-controls"></a>Para editar as propriedades de um controle ou controles  
  
1.  Na caixa de diálogo, selecione o controle que você deseja modificar.  
  
    > [!NOTE]
    >  Se você selecionar vários controles, somente as propriedades comuns para controles selecionados podem ser editadas.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), alterar as propriedades de seu controle.  
  
    > [!NOTE]
    >  Quando você define o **Bitmap** propriedade para um botão, um botão de opção ou um controle de caixa de seleção igual a **True**, o estilo BS_BITMAP é implementado para o seu controle. Para obter mais informações, consulte [estilos de botão](../mfc/reference/styles-used-by-mfc.md#button-styles). Para obter um exemplo de associar um bitmap com um controle, consulte [CButton::SetBitmap](../mfc/reference/cbutton-class.md#setbitmap). Bitmaps não aparecerão no controle enquanto você estiver no editor de recurso de caixa de diálogo.  
  
### <a name="to-undo-changes-to-the-properties-of-a-control"></a>Para desfazer as alterações nas propriedades de um controle  
  
1.  Verifique se que o controle tem foco no editor de caixa de diálogo.  
  
2.  Escolha **desfazer** do **editar** menu (se o foco não está no controle, o **desfazer** comando não estará disponível).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/en-us/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)

