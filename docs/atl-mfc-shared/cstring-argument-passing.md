---
title: "Passagem de argumentos de CString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "passagem de argumentos [C++]"
  - "passagem de argumentos [C++], Cadeias de caracteres de C"
  - "argumentos [C++], passando"
  - "Objetos de CString, passando argumentos"
  - "funções [C++], cadeias de caracteres como o arquivos entrada/saída"
  - "passando argumentos, Cadeias de caracteres de C"
  - "argumentos de cadeia de caracteres"
  - "cadeias de caracteres [C++], como o arquivos entrada/saída de função"
ms.assetid: a67bebff-edf1-4cf4-bbff-d1cc6a901099
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Passagem de argumentos de CString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como passar objetos de [CString](../atl-mfc-shared/reference/cstringt-class.md) funções e como retornar objetos de `CString` de funções.  
  
##  <a name="_core_cstring_argument.2d.passing_conventions"></a> Convenções Argumento\- Passando de CString  
 Quando você define uma interface da classe, você deve determinar a convenção argumento\- passando para suas funções de membro.  Há algumas regras padrões para passar e retornar objetos de `CString` .  Se você segue as regras descritas em [Cadeias de caracteres como entradas de função](#_core_strings_as_function_inputs) e em [Cadeias de caracteres como saída de função](#_core_strings_as_function_outputs), você terá código eficiente, correto.  
  
##  <a name="_core_strings_as_function_inputs"></a> Cadeias de caracteres como entradas de função  
 A maneira mais eficiente e mais segura de usar um objeto de `CString` em funções chamados é passar um objeto de `CString` à função.  Independentemente de nome, um objeto de `CString` não armazena uma cadeia de caracteres internamente como se AC \- estilize a cadeia de caracteres tem um terminador que zero.  Em vez de isso, um objeto de `CString` mantém a trilha cuidadosa o número de caracteres que tem.  Fazendo `CString` fornecer um ponteiro de `LPCTSTR` a uma cadeia de caracteres NULL\- finalizada é uma pequena quantidade de trabalho que pode se tornar significativa se seu código tem que fazer constantemente.  O resultado é temporário porque qualquer alteração nos conteúdos de `CString` invalida cópias antigos do ponteiro de `LPCTSTR` .  
  
 Faz sentido fornecer em alguns casos a energia AC \- estilize a cadeia de caracteres.  Por exemplo, pode haver uma situação onde uma função chamada foi escrito em C e não suporta objetos.  Em esse caso, forçar o parâmetro de `CString` a `LPCTSTR`, e a função terá a energia AC \- cadeia de caracteres NULL\- finalizada estilo.  Você também pode navegar para outra direção e criar um objeto de `CString` usando o construtor de `CString` que aceita a energia AC \- estilizar o parâmetro de cadeia de caracteres.  
  
 Se o conteúdo cadeia de caracteres devem ser modificados por uma função, declare o parâmetro como uma referência não constante `CString` \(**CString&**\).  
  
##  <a name="_core_strings_as_function_outputs"></a> Cadeias de caracteres como saída de função  
 Normalmente você pode retornar objetos de `CString` das funções como os objetos de `CString` seguem a semântica de valor como tipos primitivos.  Para retornar uma cadeia de caracteres somente leitura, use uma referência constante `CString` \(**const CString&**\).  O exemplo a seguir ilustra o uso de parâmetros e tipos de retorno de `CString` :  
  
 [!code-cpp[NVC_ATLMFC_Utilities#197](../atl-mfc-shared/codesnippet/CPP/cstring-argument-passing_1.cpp)]  
  
 [!code-cpp[NVC_ATLMFC_Utilities#198](../atl-mfc-shared/codesnippet/CPP/cstring-argument-passing_2.cpp)]  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)