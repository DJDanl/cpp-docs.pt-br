---
title: "No&#231;&#245;es b&#225;sicas de HTML | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "HTML, sobre HTML"
ms.assetid: aab8ea9f-12d4-4bdd-a585-ac3124081a2a
caps.latest.revision: 7
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de HTML
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria dos navegadores têm o recurso de examinar o código\-fonte HTML as páginas que você procura.  Quando você exibir origem que você verá um número de marcas HTML \(linguagem de marcação de hipertexto\), cercadas por colchetes angulares \(\<\>\), intercalados com o texto.  
  
 As etapas abaixo de uso HTML etiquetam para criar uma página da Web simples.  Nessas etapas, você digitará o texto sem\-formatação em um arquivo no Bloco De Notas, fará algumas alterações, salve o arquivo e, recarregará a página no navegador para ver suas alterações.  
  
#### Para criar um arquivo HTML  
  
1.  O Bloco de Notas aberto ou qualquer editor de texto sem formatação.  
  
2.  No menu de **Arquivo** , escolha `New`.  
  
3.  Digite as seguintes linhas:  
  
    ```  
    <HTML>  
    <HEAD>  
    <TITLE>Top HTML Tags</TITLE>  
    </HEAD>  
    </HTML>  
    ```  
  
4.  No menu de **Arquivo** , escolha **Salvar**, e salve o arquivo como c:\\webpages\\First.htm.  Deixe o arquivo aberto no editor.  
  
5.  Alterne para o navegador e, no menu de **Arquivo** , escolha **Abrir**, ou digite `file://C:/webpages/first.htm` na caixa de edição de URL do navegador.  Você deve ver uma página em branco com a janela subtitular “principais de marcas HTML.”  
  
     Observe que as marcas são emparelhadas e colocadas entre colchetes angulares.  As marcas não diferenciam maiúsculas de minúsculas, mas a capitalização é frequentemente usada para fazer marcas estar fora.  
  
     A marca \<HTML\> inicia o documento, e a marca \<termina\-o \/HTML\> .  As marcas de término \(obrigatório\) nem sempre são as mesmas da marca inicial, mas têm uma barra \(\/\) na frente da marca.  Não deve haver nenhum espaço entre o colchetes angulares \(\<\) e o início da marca.  
  
6.  Alterne novamente para a Bloco De Notas e \<, depois da\> linha de \/HEAD, digite:  
  
    ```  
    <BODY>  
    HTML is swell.  
    Life is good.  
    </BODY>  
    ```  
  
7.  No menu de **Arquivo** , escolha **Salvar**.  
  
8.  Alterne novamente para seu navegador e atualiza a página.  
  
     As palavras aparecerão na área da janela do navegador.  Observe que seu retorno de carro será ignorado.  Se você quer ter uma quebra de linha, você deve incluir uma marca de `<BR>` depois da primeira linha.  
  
     Para todas as etapas a seguir, inserir o texto em qualquer lugar CORPO entre \<o\> e \<o \/BODY\> para adicionar ao corpo do documento.  
  
9. Adicionar um cabeçalho:  
  
    ```  
    <H3>Here's the big picture</H3>  
    ```  
  
10. Adicionar uma imagem, usando um arquivo .gif salvo no mesmo diretório que sua página:  
  
    ```  
    <IMG src="yourfile.gif">  
    ```  
  
11. Adicionar uma lista:  
  
    ```  
    <UL>Make me an unordered list.  
    <LI>One programmer</LI>  
    <LI>Ten SDKs</LI>  
    <LI>Great Internet Apps</LI>  
    </UL>  
    ```  
  
12. Para numerar em vez da lista, use OL\> emparelhado \<e \<rótulos\> de \/OL no lugar \<de UL\> e \<dos rótulos\> do \/UL.  
  
 Isso deve começar.  Se você encontrar um grande recurso em uma página da Web, você pode saber como foi criada por meio do exame do código\-fonte HTML.  Os editores de HTML como o Microsoft Front Page podem ser usados para criar páginas simples e avançadas.  
  
 Aqui está o código\-fonte HTML inteiro para o arquivo que você tenha criado:  
  
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
  
 Para obter uma descrição completa das marcas, os atributos, e as extensões, consulte a especificação de linguagem de marcação de hipertexto \(HTML\):  
  
 [http:\/\/www.w3.org\/pub\/WWW\/MarkUp\/](http://www.w3.org/pub/WWW/MarkUp/)  
  
## Consulte também  
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)