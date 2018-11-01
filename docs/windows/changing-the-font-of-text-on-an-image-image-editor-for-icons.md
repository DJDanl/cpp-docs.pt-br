---
title: Alterando a fonte de texto em uma imagem (editor de imagens para ícones)
ms.date: 11/04/2016
helpviewer_keywords:
- fonts, changing on an image
ms.assetid: b8849d40-d401-4e06-808f-e615cb2bee3b
ms.openlocfilehash: 2bbd8096a2957099acc8c06d501f3ad407b9a974
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50495518"
---
# <a name="changing-the-font-of-text-on-an-image-image-editor-for-icons"></a>Alterando a fonte de texto em uma imagem (editor de imagens para ícones)

O procedimento a seguir é um exemplo de como:

- Adicionar texto a um ícone em um aplicativo do Windows

- Manipular a fonte do texto

### <a name="to-change-the-font-of-text-on-an-image"></a>Para alterar a fonte do texto em uma imagem

1. Crie um aplicativo de formulários do Windows do C++. Para obter detalhes, consulte [criando um projeto de aplicativo do Windows](/previous-versions/visualstudio/visual-studio-2010/42wc9kk5). Um `app.ico` arquivo é adicionado ao seu projeto por padrão.

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

[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Toolbar](../windows/toolbar-image-editor-for-icons.md)