---
title: Editando partes de uma imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Image editor [C++], editing images
- Clipboard [C++], pasting
- images [C++], editing
- images [C++], deleting selected parts
- images [C++], copying selected parts
- images [C++], moving selected parts
- images [C++], dragging and replicating selected parts
- images [C++], pasting into
- graphics [C++], editing
ms.assetid: ff4f5fef-71a4-4fd8-825e-049399fed391
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b33a591a2f38062b5eaf81b0f56ab73a36f4c90c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="editing-parts-of-an-image-image-editor-for-icons"></a>Editando partes de uma imagem (editor de imagens para ícones)
Você pode executar operações de edição padrão — recortar, copiar, limpar e mover — em uma [seleção](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md), se a seleção for a imagem inteira ou apenas uma parte dele. Como o editor de imagem usa a área de transferência do Windows, você pode transferir imagens entre o editor de imagens e outros aplicativos do Windows.  
  
 Além disso, você pode redimensionar a seleção, se ele inclui a imagem inteira ou apenas uma parte.  
  
### <a name="to-cut-the-current-selection-and-move-it-to-the-clipboard"></a>Recortar a seleção atual e movê-la na área de transferência  
  
1.  Clique em **Recortar** no **editar** menu.  
  
### <a name="to-copy-the-selection"></a>Para copiar a seleção  
  
1.  Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar, nele, exceto as alças de dimensionamento.  
  
2.  Mantenha pressionada a **CTRL** enquanto você arrasta a seleção para um novo local da chave. A área da seleção original permanece inalterada.  
  
3.  Para copiar a seleção para a imagem em seu local atual, clique fora do cursor de seleção.  
  
### <a name="to-paste-the-clipboard-contents-into-an-image"></a>Para colar o conteúdo da área de transferência em uma imagem  
  
1.  Do **editar** menu, escolha **colar**.  
  
     O conteúdo da área de transferência, entre a borda de seleção, aparece no canto superior esquerdo do painel.  
  
2.  Posicione o ponteiro dentro da borda de seleção e arraste a imagem para o local desejado na imagem.  
  
3.  Para fixar a imagem em seu novo local, clique fora da borda de seleção.  
  
### <a name="to-delete-the-current-selection-without-moving-it-to-the-clipboard"></a>Para excluir a seleção atual sem movê-lo na área de transferência  
  
1.  Do **editar** menu, escolha **excluir**.  
  
     A área original da seleção é preenchida com a cor de plano de fundo atual.  
  
    > [!NOTE]
    >  Você pode acessar o recortar, copiar, colar e excluir comandos, clique com o botão direito na janela de exibição de recursos.  
  
### <a name="to-move-the-selection"></a>Para mover a seleção  
  
1.  Posicione o ponteiro dentro da borda de seleção ou em qualquer lugar, nele, exceto as alças de dimensionamento.  
  
2.  Arraste a seleção para o novo local.  
  
3.  Para fixar a seleção da imagem em seu novo local, clique fora da borda de seleção.  
  
 Para obter mais informações sobre o desenho de uma seleção, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

