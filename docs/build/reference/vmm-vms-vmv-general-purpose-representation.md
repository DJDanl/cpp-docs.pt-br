---
title: "/vmm, /vms, /vmv (representa&#231;&#227;o de finalidade geral) | Microsoft Docs"
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
  - "/vms"
  - "/vmm"
  - "/vmv"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /vmm (C++)"
  - "Opção de compilador /vms (C++)"
  - "Opção de compilador /vmv (C++)"
  - "opções de compilador de representação de finalidade geral"
  - "Opção de compilador Herança Única"
  - "Opção de compilador Herança Virtual"
  - "Opção de compilador vmm [C++]"
  - "Opção de compilador -vmm [C++]"
  - "Opção de compilador vms [C++]"
  - "Opção de compilador -vms [C++]"
  - "Opção de compilador vmv [C++]"
  - "Opção de compilador -vmv [C++]"
ms.assetid: 0fcd7ae0-3031-4c62-a2a8-e154c8685dae
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /vmm, /vms, /vmv (representa&#231;&#227;o de finalidade geral)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado quando [\/vmb, \/vmg \(método de representação\)](../../build/reference/vmb-vmg-representation-method.md) é selecionado como [método de representação](../../build/reference/vmb-vmg-representation-method.md).  Essas opções indicam o modelo de herança da definição de classe não\-ainda\- encontrada.  
  
## Sintaxe  
  
```  
/vmm  
/vms  
/vmv  
```  
  
## Comentários  
 As opções são descritas na tabela a seguir.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**\/vmm**|Especifica a representação geral a mais de um ponteiro para um membro de uma classe para ser uma que usa a herança múltipla.<br /><br /> [palavras\-chave de herança](../../cpp/inheritance-keywords.md) e o argumento correspondentes a [pointers\_to\_members de \#pragma](../Topic/pointers_to_members.md) são **multiple\_inheritance**.<br /><br /> Essa representação é maior do que aquela exigida para uma herança.<br /><br /> Se o modelo de herança de uma definição de classe para que um ponteiro para um membro é declarado é virtual, o compilador gerencie um erro.|  
|**\/vms**|Especifica a representação geral a mais de um ponteiro para um membro de uma classe para ser uma que não usa nenhuma herança ou a única herança.<br /><br /> [palavras\-chave de herança](../../cpp/inheritance-keywords.md) e o argumento correspondentes a [pointers\_to\_members de \#pragma](../Topic/pointers_to_members.md) são **single\_inheritance**.<br /><br /> Esta é a representação possível a menor de um ponteiro para um membro de uma classe.<br /><br /> Se o modelo de herança de uma definição de classe para que um ponteiro para um membro é declarado é mais ou virtual, o compilador gerencie um erro.|  
|**\/vmv**|Especifica a representação geral a mais de um ponteiro para um membro de uma classe para ser uma que usa a herança virtual.  Nunca causa um erro e é o padrão.<br /><br /> [palavras\-chave de herança](../../cpp/inheritance-keywords.md) e o argumento correspondentes a [pointers\_to\_members de \#pragma](../Topic/pointers_to_members.md) são **virtual\_inheritance**.<br /><br /> Essa opção requer um ponteiro maior e um código adicional interpretar o ponteiro das outras opções.|  
  
 Quando você especifica uma dessas opções de herança\- modelo, esse modelo é usado para que todos os ponteiros para classificar serialmente membros, independentemente do tipo de herança ou se o ponteiro está declarada antes ou depois da classe.  Em virtude disso, se você usar sempre classes de uma herança, você pode reduzir o tamanho de código compilando com **\/vms**; porém, se você desejar usar os casos os mais gerais \(às custas da representação de dados maior\), compile com **\/vmv**.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/vmb, \/vmg \(método de representação\)](../../build/reference/vmb-vmg-representation-method.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)