---
title: "/GH (habilitar fun&#231;&#227;o de gancho _pexit) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_pexit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gh (C++)"
  - "Função _pexit"
  - "Opção de compilador Gh [C++]"
  - "Opção de compilador -Gh [C++]"
ms.assetid: 93181453-2676-42e5-bf63-3b19e07299b6
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GH (habilitar fun&#231;&#227;o de gancho _pexit)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama a função de `_pexit` o final de cada método ou função.  
  
## Sintaxe  
  
```  
/GH  
```  
  
## Comentários  
 A função de `_pexit` não é parte de qualquer biblioteca e cabe a você para fornecer uma definição para `_pexit`.  
  
 A menos que você planejar para chamar explicitamente `_pexit`, você não precisa fornecer um protótipo.  A função deve aparecer como se tivesse o seguinte protótipo, e deve enviar o conteúdo de todos os registros na entrada e o conteúdo inalterado aparecer na saída:  
  
```  
void __declspec(naked) _cdecl _pexit( void );  
```  
  
 `_pexit` é semelhante a `_penter`; consulte [\/Gh \(habilitar função de gancho \_penter\)](../../build/reference/gh-enable-penter-hook-function.md) para obter um exemplo de como escrever uma função de `_pexit` .  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)