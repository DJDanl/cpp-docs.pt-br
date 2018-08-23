---
title: Alterando a fonte do texto em uma imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- fonts, changing on an image
ms.assetid: b8849d40-d401-4e06-808f-e615cb2bee3b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f5a86748d5a51e433e2e90450593ef1bac1c8de3
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596275"
---
# <a name="changing-the-font-of-text-on-an-image-image-editor-for-icons"></a>Alterando a fonte de texto em uma imagem (editor de imagens para ícones)

O procedimento a seguir é um exemplo de como:

- Adicionar texto a um ícone em um aplicativo do Windows

- Manipular a fonte do texto

### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem

1. Crie um aplicativo de formulários do Windows do C++. Para obter detalhes, consulte [criando um projeto de aplicativo do Windows](http://msdn.microsoft.com/b2f93fed-c635-4705-8d0e-cf079a264efa). O [modelo de aplicativo do Windows Forms](http://msdn.microsoft.com/1babdebf-ab3f-4a64-a608-98499a5b9cea) adiciona um arquivo chamado `app.ico` ao seu projeto por padrão.

2. Na **Gerenciador de soluções**, clique duas vezes em app.ico o arquivo. O [Editor de imagens](../windows/image-editor-for-icons.md) será aberta.

3. Dos **imagem** menu, selecione **ferramentas** e, em seguida, selecione **ferramenta de texto**. O [caixa de diálogo Ferramenta de texto](../windows/text-tool-dialog-box-image-editor-for-icons.md) será exibida.

4. No **ferramenta de texto** caixa de diálogo, digite `C++` na área de texto vazio. Esse texto será exibido em uma caixa redimensionável localizada no canto superior esquerdo do `app.ico`, no **Editor de imagens**.

5. No **Editor de imagens**, arraste a caixa redimensionável para o centro do app.ico, para melhorar a legibilidade do texto.

6. No **ferramenta de texto** caixa de diálogo, clique o **fonte** botão. O [caixa de diálogo fonte da ferramenta de texto](../windows/text-tool-font-dialog-box-image-editor-for-icons.md) será exibida.

7. No **fonte da ferramenta de texto** caixa de diálogo, selecione **Times New Roman** da lista de fontes disponíveis que estão listados no **fonte** caixa de listagem.

8. Selecione **Bold** na lista de estilos de fonte disponíveis listadas na **estilo da fonte** caixa de listagem.

9. Selecione **10** na lista de disponíveis de tamanhos listados no ponto de **tamanho** caixa de listagem.

10. Clique o **Okey** botão. O **da fonte de dados da ferramenta texto** caixa de diálogo será fechada e as novas configurações de fonte serão aplicada ao texto.

11. Clique no **feche** botão a **ferramenta texto** caixa de diálogo. A caixa ao redor do texto de redimensionável desaparecerá dos **Editor de imagens**.

## <a name="see-also"></a>Consulte também

[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)  
[Toolbar](../windows/toolbar-image-editor-for-icons.md)