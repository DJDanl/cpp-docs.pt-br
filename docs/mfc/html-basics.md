---
title: Noções básicas de HTML
ms.date: 11/04/2016
helpviewer_keywords:
- HTML [MFC], about HTML
ms.assetid: aab8ea9f-12d4-4bdd-a585-ac3124081a2a
ms.openlocfilehash: 7617216f8fd9a0e4b62ac8b5f12314d38027d836
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263358"
---
# <a name="html-basics"></a>Noções básicas de HTML

A maioria dos navegadores têm a capacidade de examinar o código-fonte HTML das páginas de que procurar por você. Quando você exibir a fonte, você verá um número de marcas do HTML (linguagem de marcação de hipertexto), delimitado por colchetes angulares (<>) intercalados com texto.

As etapas abaixo usam marcas HTML para criar uma página da Web simple. Nestas etapas, você vai texto sem formatação em um arquivo no bloco de notas, fazer algumas alterações, salve o arquivo e recarregar a página no navegador para ver suas alterações.

#### <a name="to-create-an-html-file"></a>Para criar um arquivo HTML

1. Abra o bloco de notas ou em qualquer editor de texto sem formatação.

1. Dos **arquivo** menu, escolha **New**.

1. Digite as seguintes linhas:

```
<HTML>
<HEAD>
<TITLE>Top HTML Tags</TITLE>
</HEAD>
</HTML>
```

1. Dos **arquivo** menu, escolha **salvar**e salve o arquivo como c:\webpages\First.htm. Deixe o arquivo aberto no editor.

1. Comutador de seu navegador e para o **arquivo** menu, escolha **aberto**, ou tipo *file://C:/webpages/first.htm* na caixa de edição de URL do navegador. Você deve ver uma página em branco com a legenda da janela "Principais marcas HTML".

   Observe que as marcas são emparelhadas e são incluídas entre colchetes angulares. As marcas não diferenciam maiusculas de minúsculas, mas maiusculas e minúsculas é frequentemente usada para destacar as marcas.

   A marca \<HTML > inicia o documento e a marca \</HTML mais externas > termina a ele. Marcas de fim (nem sempre necessárias) são o mesmo que a marca inicial, mas tem uma barra (/) na frente da marca. Não deve haver nenhum espaço entre o colchete angular (<) e o início de sua marca.

1. Alternar de volta para o bloco de notas e, depois do  \< /HEAD >, digite:

```
<BODY>
    HTML is swell.
    Life is good.
</BODY>
```

1. Dos **arquivo** menu, escolha **salvar**.

1. Volte para o seu navegador e atualize a página.

   As palavras, aparecerão na área de cliente da janela do navegador. Observe que o seu retorno de carro é ignorado. Se você quiser ter uma quebra de linha, você deve incluir um `<BR>` marca depois da primeira linha.

   Para todas as etapas a seguir, insira o texto em qualquer lugar entre \<BODY > e  \< /BODY > para adicionar ao corpo do documento.

9. Adicione um cabeçalho:

```
<H3>Here's the big picture</H3>
```

10. Adicione uma imagem, usando um arquivo. gif salvo no mesmo diretório que sua página:

```
<IMG src="yourfile.gif">
```

11. Adicione uma lista:

```
<UL>Make me an unordered list.
<LI>One programmer</LI>
<LI>Ten SDKs</LI>
<LI>Great Internet Apps</LI>
</UL>
```

12. A lista de números em vez disso, use emparelhado \<OL > e \</ol > marcas em vez da \<UL > e  \< /ul > marcas.

Que deve começar. Se você vir um ótimo recurso em uma página da Web, você pode descobrir como ele foi criado por meio do exame do código-fonte HTML. Editores de HTML, como página inicial da Microsoft podem ser usados para criar páginas simples e avançadas.

Aqui está o código-fonte do HTML inteiro para o arquivo que você já cria:

```
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

Para obter uma descrição completa de marcas, atributos e extensões, consulte a especificação de Hypertext Markup Language (HTML):

[http://www.w3.org/pub/WWW/MarkUp/](http://www.w3.org/pub/www/markup/)

## <a name="see-also"></a>Consulte também

[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)
