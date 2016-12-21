---
title: "Erro das Ferramentas de Vinculador LNK2022 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2022"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2022"
ms.assetid: d2128c73-dde3-4b8e-a9b2-0a153acefb3b
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2022
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

falha na operação de metadados \(HRESULT\): error\_message  
  
 O vinculador detectou um erro ao mesclar metadados.  Os erros de metadados devem ser resolvidos para vincular com êxito.  
  
 Uma maneira de diagnosticar esse problema é executar **ildasm –tokens** nos arquivos de objeto para localizar os tipos que têm os tokens listados em `error_message`, e para procurar diferenças.  Nos metadados, dois tipos diferentes com o mesmo nome não são válidas, mesmo se o atributo razoável de LayoutType é diferente.  
  
 Um motivo para LNK2022 ocorre quando um tipo \(como uma estrutura\) existe em vários compilands com o mesmo nome, mas com conflitantes definições e, quando você compile com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  Nesse caso, certifique\-se de que o tipo tem uma definição de forma idêntica em todos os compilands.  O nome do tipo é listado em `error_message`.  
  
 Outra causa possível para LNK2022 é quando o vinculador localiza metadados arquivos em um local diferente do que foi especificada ao compilador \(com [\#using](../../preprocessor/hash-using-directive-cpp.md) \).  Certifique\-se de que o arquivo de metadados \(.dll\) ou .netmodule estiver no mesmo local quando é passada ao vinculador, como ele estava quando foi passado ao compilador.  
  
 Ao criar um aplicativo de ATL, o uso de [\_ATL\_MIXED](../Topic/_ATL_MIXED.md) é necessário em todos os compilands, se for usado em pelo menos um.  
  
## Exemplo  
 O exemplo a seguir define um tipo vazia.  
  
```  
// LNK2022_a.cpp  
// compile with: /clr /c  
public ref class Test {};  
```  
  
## Exemplo  
 Este exemplo mostra que não é possível vincular dois arquivo de origem que contêm tipos de mesmo nome de mas diferentes definições.  
  
 O exemplo a seguir produz LNK2022.  
  
```  
// LNK2022_b.cpp  
// compile with: LNK2022_a.cpp /clr /LD   
// LNK2022 expected  
public ref class Test {  
   void func() {}  
   int var;  
};  
```