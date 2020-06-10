---
title: Noções básicas de HTML
ms.date: 11/04/2016
helpviewer_keywords:
- HTML [MFC], about HTML
ms.assetid: aab8ea9f-12d4-4bdd-a585-ac3124081a2a
ms.openlocfilehash: 29ca2e3df4981db22a10281ba2a2938fc91d5b46
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619996"
---
# <a name="html-basics"></a>Noções básicas de HTML

A maioria dos navegadores tem a capacidade de examinar a origem HTML das páginas que você navega. Ao exibir a origem, você verá várias marcas HTML (Hypertext Markup Language), cercadas por colchetes angulares (<>), intercaladas com texto.

As etapas a seguir usam marcas HTML para criar uma página da Web simples. Nestas etapas, você digitará texto sem formatação em um arquivo no bloco de notas, fará algumas alterações, salvará o arquivo e recarregará sua página no navegador para ver suas alterações.

#### <a name="to-create-an-html-file"></a>Para criar um arquivo HTML

1. Abra o bloco de notas ou qualquer editor de texto sem formatação.

1. No menu **arquivo** , escolha **novo**.

1. Digite as seguintes linhas:

    ```html
    <HTML>
    <HEAD>
    <TITLE>Top HTML Tags</TITLE>
    </HEAD>
    </HTML>
    ```

1. No menu **arquivo** , escolha **salvar**e salve o arquivo como c:\webpages\First.htm. Deixe o arquivo aberto no editor.

1. Alterne para o navegador e, no menu **arquivo** , escolha **abrir**ou digite *file://C:/WEBPAGES/First.htm* na caixa de edição URL do navegador. Você deve ver uma página em branco com a legenda da janela "Top HTML Tags".

   Observe que as marcas são emparelhadas e incluídas entre colchetes angulares. As marcas não diferenciam maiúsculas de minúsculas, mas a capitalização é geralmente usada para destacar as marcas.

   A marca \<HTML> inicia o documento e a marca \</HTML> termina. Marcas de fim (nem sempre necessárias) são as mesmas que a marca de início, mas têm uma barra (/) na frente da marca. Não deve haver nenhum espaço entre o colchete angular (<) e o início da sua marca.

1. Volte para o bloco de notas e, depois da \</HEAD> linha, digite:

    ```html
    <BODY>
        HTML is swell.
        Life is good.
    </BODY>
    ```

1. No menu **arquivo** , escolha **salvar**.

1. Volte para o navegador e atualize a página.

   As palavras aparecerão na área cliente da janela do navegador. Observe que o retorno de carro é ignorado. Se você quiser ter uma quebra de linha, deverá incluir uma `<BR>` marca após a primeira linha.

   Para todas as etapas a seguir, insira o texto em qualquer lugar entre \<BODY> e \</BODY> para adicionar ao corpo do documento.

1. Adicionar um cabeçalho:

    ```html
    <H3>Here's the big picture</H3>
    ```

1. Adicione uma imagem, usando um arquivo. gif salvo no mesmo diretório da sua página:

    ```html
    <IMG src="yourfile.gif">
    ```

1. Adicionar uma lista:

    ```html
    <UL>Make me an unordered list.
    <LI>One programmer</LI>
    <LI>Ten SDKs</LI>
    <LI>Great Internet Apps</LI>
    </UL>
    ```

1. Para numerar a lista, use as marcas emparelhadas \<OL> e \</OL> em vez das \<UL> \</UL> marcas e.

Isso deve ajudá-lo a começar. Se você vir um ótimo recurso em uma página da Web, poderá descobrir como ele foi criado examinando a origem HTML. Editores de HTML, como o Microsoft Front Page, podem ser usados para criar páginas simples e avançadas.

Aqui está a fonte HTML inteira para o arquivo que você está criando:

```html
<HTML>
<HEAD>
<TITLE>Top HTML Tags</TITLE>
</HEAD>
<BODY>
HTML is swell.<BR>
Life is good.
<H3>Here's the big picture</H3>
<IMG src="yourfile.gif">
<UL>Make me an unordered list.
<LI>One programmer</LI>
<LI>Ten SDKs</LI>
<LI>Great Internet Apps</LI>
</UL>
</BODY>
</HTML>
```

Para obter uma descrição completa de marcas, atributos e extensões, consulte a especificação de linguagem HTML (HTML):

[Versão publicada mais recente do HTML](https://www.w3.org/TR/html/) em W3C.org.

## <a name="see-also"></a>Consulte também

[Noções básicas de programação na Internet do MFC](mfc-internet-programming-basics.md)
