---
title: Noções básicas de HTML
ms.date: 11/04/2016
helpviewer_keywords:
- HTML [MFC], about HTML
ms.assetid: aab8ea9f-12d4-4bdd-a585-ac3124081a2a
ms.openlocfilehash: 6d3a692eab47a1309ee0248b51ab8563fb077d5a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377241"
---
# <a name="html-basics"></a>Noções básicas de HTML

A maioria dos navegadores tem a capacidade de examinar a fonte HTML das páginas que você navega. Quando você visualizar a fonte, você verá um número de tags HTML (Hypertext markup language), cercadas por suportes angulares (<>), intercaladas com texto.

As etapas abaixo usam tags HTML para construir uma página da Web simples. Nestas etapas, você digitará texto simples em um arquivo no Bloco de Notas, fará algumas alterações, salvará o arquivo e recarregará sua página no navegador para ver suas alterações.

#### <a name="to-create-an-html-file"></a>Para criar um arquivo HTML

1. Abra o Bloco de Notas ou qualquer editor de texto simples.

1. No menu **Arquivo,** escolha **Novo**.

1. Digite as seguintes linhas:

    ```html
    <HTML>
    <HEAD>
    <TITLE>Top HTML Tags</TITLE>
    </HEAD>
    </HTML>
    ```

1. No menu **Arquivo,** escolha **Salvar**e salve o arquivo como c:\webpages\First.htm. Deixe o arquivo aberto no editor.

1. Mude para o seu navegador e, no menu **Arquivo,** escolha **Abrir**ou *digite file://C:/webpages/first.htm* na caixa de edição de URL do navegador. Você deve ver uma página em branco com a legenda da janela "Top HTML Tags".

   Observe que as tags estão emparelhadas e estão incluídas em suportes angulares. As tags não são sensíveis a maiúsculas e minúsculas, mas a capitalização é frequentemente usada para fazer com que as tags se destaquem.

   A \<tag HTML> inicia o \<documento, e a> tag /HTML termina com ele. As tags de término (nem sempre necessárias) são as mesmas da tag inicial, mas têm uma barra para a frente (/) na frente da tag. Não deve haver espaços entre o suporte de ângulo (<) e o início da sua tag.

1. Volte para o Bloco de \<Notas e, após a linha /HEAD>, digite:

    ```html
    <BODY>
        HTML is swell.
        Life is good.
    </BODY>
    ```

1. No menu **Arquivo,** escolha **Salvar**.

1. Volte para o seu navegador e atualize a página.

   As palavras aparecerão na área cliente da janela do seu navegador. Note que seu retorno de carruagem é ignorado. Se você quiser ter uma quebra de `<BR>` linha, você deve incluir uma tag após a primeira linha.

   Para todas as etapas a seguir, insira o texto em qualquer lugar entre \<body> e \</BODY> para adicionar ao corpo do seu documento.

1. Adicione um cabeçalho:

    ```html
    <H3>Here's the big picture</H3>
    ```

1. Adicione uma imagem, usando um arquivo .gif salvo no mesmo diretório da página:

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

1. Para numerar a lista, \<use tags \<oL> e /OL> emparelhadas no lugar das \<tags ul> e \</UL>.

Isso deve começar. Se você ver um grande recurso em uma página da Web, você pode descobrir como ele foi criado examinando a fonte HTML. Editores HTML, como o Microsoft Front Page, podem ser usados para criar páginas simples e avançadas.

Aqui está toda a fonte HTML para o arquivo que você está construindo:

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

Para obter uma descrição completa das tags, atributos e extensões, consulte a especificação HTML (Hypertext Markup Language:

[Última versão publicada de HTML](https://www.w3.org/TR/html/) em W3C.org.

## <a name="see-also"></a>Confira também

[Noções básicas de programação da Internet Do MFC](../mfc/mfc-internet-programming-basics.md)
