---
title: "section | Microsoft Docs"
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
  - "section_CPP"
  - "vc-pragma.section"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragmas, seção"
  - "pragma de seção"
ms.assetid: c67215e9-2c4a-4b0f-b691-2414d2e2d96f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# section
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma seção em um arquivo. obj.  
  
## Sintaxe  
  
```  
  
#pragma section(  
"  
section-name  
" [, attributes] )  
```  
  
## Comentários  
 O significado dos termos *segmento* e *seção* são intercambiáveis neste tópico.  
  
 Quando uma seção for definida, permanece válida pelo restante da compilação. No entanto, você deve usar [\_\_declspec\(allocate\)](../Topic/allocate.md) ou nada será colocado na seção.  
  
 *nome da seção* é um parâmetro obrigatório que será o nome da seção. O nome não deve entrar em conflito com qualquer nome de seção padrão. Consulte [\/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
 `attributes` é um parâmetro opcional que consiste em um ou mais atributos de separados por vírgulas que você deseja atribuir à seção. Possíveis `attributes` são:  
  
 **read**  
 Permite operações de leitura nos dados.  
  
 **write**  
 Permite operações de gravação nos dados.  
  
 **executar**  
 Permite que o código a ser executado.  
  
 **shared**  
 Compartilha a seção entre todos os processos que carregam a imagem.  
  
 **noPage**  
 Marca a seção como não paginável; útil para drivers de dispositivo do Win32.  
  
 **NoCache**  
 Marca a seção como não armazenável em cache; útil para drivers de dispositivo do Win32.  
  
 **Descartar**  
 Marca a seção como descartável; útil para drivers de dispositivo do Win32.  
  
 **remove**  
 Marca a seção como não residentes na memória; drivers de dispositivo virtual \(V*x*D\) apenas.  
  
 Se você não especificar atributos, a seção terão de leitura e gravação de atributos.  
  
## Exemplo  
 No exemplo a seguir, a primeira instrução identifica a seção e seus atributos. O inteiro `j` não é colocado no `mysec` porque não foi declarado com `__declspec(allocate)`; `j` vai para a seção de dados. O inteiro `i` acesse `mysec` como resultado de sua `__declspec(allocate)` atributo de classe de armazenamento.  
  
```  
// pragma_section.cpp  
#pragma section("mysec",read,write)  
int j = 0;  
  
__declspec(allocate("mysec"))  
int i = 0;  
  
int main(){}  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)