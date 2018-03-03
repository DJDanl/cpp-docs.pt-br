---
title: "Alterar a fonte do texto em uma imagem (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- fonts, changing on an image
ms.assetid: b8849d40-d401-4e06-808f-e615cb2bee3b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 07dc7d7fd74ad9d4b0229ffef7cf4e96a4ea44b4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-the-font-of-text-on-an-image-image-editor-for-icons"></a>Alterando a fonte de texto em uma imagem (editor de imagens para ícones)
O procedimento a seguir é um exemplo de como:  
  
-   Adicionar texto a um ícone em um aplicativo do Windows  
  
-   Manipular a fonte do texto  
  
### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem  
  
1.  Crie um aplicativo de formulários do Windows do C++. Para obter detalhes, consulte [criando um projeto de aplicativo do Windows](http://msdn.microsoft.com/en-us/b2f93fed-c635-4705-8d0e-cf079a264efa). O [modelo de aplicativo do Windows Forms](http://msdn.microsoft.com/en-us/1babdebf-ab3f-4a64-a608-98499a5b9cea) adiciona um arquivo chamado app.ico ao seu projeto por padrão.  
  
2.  No Solution Explorer, clique duas vezes o arquivo app.ico. O [Editor de imagem](../windows/image-editor-for-icons.md) será aberto.  
  
3.  Do **imagem** menu, selecione **ferramentas** e, em seguida, selecione **ferramenta texto**. O [caixa de diálogo Ferramenta de texto](../windows/text-tool-dialog-box-image-editor-for-icons.md) será exibida.  
  
4.  Na caixa de diálogo Ferramenta de texto, digite `C++` na área de texto vazio. Esse texto aparecerá em uma caixa redimensionável localizada no canto superior esquerdo do app.ico, no Editor de imagem.  
  
5.  No Editor de imagem, arraste a caixa redimensionável para o centro da app.ico, para melhorar a legibilidade do texto.  
  
6.  Na caixa de diálogo Ferramenta de texto, clique no **fonte** botão. O [caixa de diálogo de fonte do texto ferramenta](../windows/text-tool-font-dialog-box-image-editor-for-icons.md) será exibida.  
  
7.  Na caixa de diálogo fonte de ferramenta de texto, selecione **Times New Roman** da lista de fontes disponíveis que são listadas no **fonte** caixa de listagem.  
  
8.  Selecione **negrito** na lista de estilos de fonte disponíveis listadas no **estilo de fonte** caixa de listagem.  
  
9. Selecione **10** da lista de disponíveis ponto tamanhos listados no **tamanho** caixa de listagem.  
  
10. Clique o **Okey** botão. Caixa de diálogo de fonte da ferramenta de texto será fechado e as novas configurações de fonte serão aplicada ao texto.  
  
11. Clique o **fechar** botão na caixa de diálogo Ferramenta de texto. A caixa ao redor do texto de redimensionável desaparecerá do Editor de imagem.  
  
## <a name="see-also"></a>Consulte também  
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Barra de ferramentas](../windows/toolbar-image-editor-for-icons.md)

