---
title: "Noções básicas de HTML | Microsoft Docs"
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
- HTML [MFC], about HTML
ms.assetid: aab8ea9f-12d4-4bdd-a585-ac3124081a2a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 852a4894478d139013d70813316976a20e99dd41
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="html-basics"></a>Noções básicas de HTML
A maioria dos navegadores têm a capacidade de examinar a fonte HTML das páginas que você procura. Quando você exibir a fonte, você verá um número de marcas do HTML (linguagem de marcação de hipertexto), entre colchetes angulares (<>), intercalados com texto.  
  
 As etapas a seguir usam marcas HTML para criar uma página da Web simple. Nestas etapas, você será texto sem formatação em um arquivo no bloco de notas, fazer algumas alterações, salve o arquivo e recarregue a página no navegador para ver as alterações.  
  
#### <a name="to-create-an-html-file"></a>Para criar um arquivo HTML  
  
1.  Abra o bloco de notas ou em qualquer editor de texto sem formatação.  
  
2.  Do **arquivo** menu, escolha `New`.  
  
3.  Digite as seguintes linhas:  
  
 ```  
 <HTML>  
 <HEAD>  
 <TITLE>Top HTML Tags</TITLE>  
 </HEAD>  
 </HTML>  
 ```  
  
4.  Do **arquivo** menu, escolha **salvar**e salve o arquivo como c:\webpages\First.htm. Deixe o arquivo aberto no editor.  
  
5.  Comutador de seu navegador e o **arquivo** menu, escolha **abrir**, ou tipo `file://C:/webpages/first.htm` na caixa de edição de URL do navegador. Você deve ver uma página em branco com a legenda da janela "Principais marcas HTML."  
  
     Observe as marcas associadas e são incluídas entre colchetes. Marcas não diferenciam maiusculas de minúsculas, mas o uso de maiusculas geralmente é usado para destacar as marcas.  
  
     A marca \<HTML > inicia o documento e a marca \</HTML mais externas > termina a ele. Marcas de término (nem sempre necessárias) são iguais a marca inicial, mas têm uma barra invertida (/) na frente da marca. Não deve haver nenhum espaço entre o colchete angular (<) e o início da sua marca.  
  
6.  Alternar de volta para o bloco de notas e depois o  \< /HEAD > linha, digite:  
  
 ```  
 <BODY>  
    HTML is swell.  
    Life is good.  
 </BODY>  
 ```  
  
7.  Do **arquivo** menu, escolha **salvar**.  
  
8.  Alterne para o seu navegador e atualize a página.  
  
     As palavras que serão exibido na área de cliente da janela do navegador. Observe que o retorno de carro é ignorado. Se você quiser ter uma quebra de linha, você deve incluir um `<BR>` marca depois da primeira linha.  
  
     Para todas as etapas a seguir, insira o texto em qualquer lugar entre \<corpo > e  \< /BODY > Adicionar ao corpo do documento.  
  
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
  
12. A lista de números em vez disso, use emparelhado \<OL > e \</ol > marcas em vez do \<UL > e  \< /ul > marcas.  
  
 Que deve ajudá-lo iniciado. Se você vir um ótimo recurso em uma página da Web, você pode descobrir como ele foi criado por meio do exame do código-fonte HTML. Editores de HTML como página inicial da Microsoft podem ser usados para criar páginas simples e avançadas.  
  
 Aqui está a toda a origem do HTML para o arquivo que você já cria:  
  
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
  
 Para obter uma descrição completa de marcas, atributos e extensões, consulte a especificação de linguagem de marcação de hipertexto (HTML):  
  
 [http://www.w3.org/pub/www/MarkUp/](http://www.w3.org/pub/www/markup/)  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

