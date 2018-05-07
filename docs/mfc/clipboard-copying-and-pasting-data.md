---
title: 'Área de transferência: Copiando e colando dados | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Clipboard, copying data to
- Clipboard, pasting
ms.assetid: 580e10be-241f-4f9f-94cf-8302edc5beef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bdfd43933453e44c49d713a1565ac3f71e019de4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="clipboard-copying-and-pasting-data"></a>Área de Transferência: copiando e colando dados
Este tópico descreve o trabalho mínimo necessário para implementar a copiar e colar da área de transferência no seu aplicativo OLE. É recomendável que você leia o [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) tópicos antes de continuar.  
  
 Antes de implementar a copiar e colar, primeiro você deve fornecer funções para lidar com as opções de copiar, recortar e colar no menu Editar.  
  
##  <a name="_core_copying_or_cutting_data"></a> Copiar ou dados de recorte  
  
#### <a name="to-copy-data-to-the-clipboard"></a>Para copiar dados para a área de transferência  
  
1.  Determine se os dados a serem copiados são dados nativos ou é um item inserido ou vinculado.  
  
    -   Se os dados são inseridos ou vinculados, obter um ponteiro para o `COleClientItem` objeto que foi selecionado.  
  
    -   Se os dados são nativo e o aplicativo é um servidor, crie um novo objeto derivado de `COleServerItem` que contém os dados selecionados. Caso contrário, crie um `COleDataSource` objeto para os dados.  
  
2.  Chame o item selecionado `CopyToClipboard` função de membro.  
  
3.  Se o usuário optou por uma operação de transferência, em vez de uma operação de cópia, exclua os dados selecionados do seu aplicativo.  
  
 Para ver um exemplo dessa sequência, consulte o **OnEditCut** e **OnEditCopy** programas de exemplo de funções de MFC OLE [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md). Observe que esses exemplos mantenham um ponteiro para os dados selecionados no momento, portanto, etapa 1 já está concluída.  
  
##  <a name="_core_pasting_data"></a> Colando dados  
 Colando dados é mais complicado do que copiá-lo porque você precisa escolher o formato a ser usado em colando os dados em seu aplicativo.  
  
#### <a name="to-paste-data-from-the-clipboard"></a>Para colar os dados da área de transferência  
  
1.  Em sua classe de exibição, implementar **OnEditPaste** para lidar com usuários escolhendo a opção de colar no menu Editar.  
  
2.  No **OnEditPaste** funcionar, crie um `COleDataObject` objeto e chame seu `AttachClipboard` função de membro para vincular esse objeto para os dados na área de transferência.  
  
3.  Chamar `COleDataObject::IsDataAvailable` para verificar se um formato específico está disponível.  
  
     Como alternativa, você pode usar `COleDataObject::BeginEnumFormats` para procurar por outros formatos até encontrar um mais adequado ao seu aplicativo.  
  
4.  Execute a operação de colagem do formato.  
  
 Para obter um exemplo de como isso funciona, consulte a implementação de **OnEditPaste** funções de membro em classes de exibição definidas em programas de exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).  
  
> [!TIP]
>  O principal benefício de separar a operação de colagem em sua própria função é que o mesmo código de colar pode ser usado quando dados são descartados em seu aplicativo durante uma operação de arrastar e soltar. Como OCLIENT e HIERSVR, seu `OnDrop` também pode chamar a função **DoPasteItem**, reutilizando o código escrito para implementar operações de colagem.  
  
 Para lidar com a opção de colar especial no menu Editar, consulte o tópico [caixas de diálogo em OLE](../mfc/dialog-boxes-in-ole.md).  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)  
  
-   [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)  
  
-   [Arrastar e soltar OLE](../mfc/drag-and-drop-ole.md)  
  
-   [OLE](../mfc/ole-background.md)  
  
## <a name="see-also"></a>Consulte também  
 [Área de transferência: usando o mecanismo de área de transferência do OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

