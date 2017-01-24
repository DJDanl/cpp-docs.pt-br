---
title: "/GT (armazenamento local de thread seguro de fibra de suporte) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.EnableFiberSafeOptimizations"
  - "/gt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /GT (C++)"
  - "Opção de compilador de armazenamento local de threads estático de fibra segura [C++]"
  - "Opção de compilador GT [C++]"
  - "Opção de compilador -GT [C++]"
  - "armazenamento local de threads estático e segurança de fibra"
  - "armazenamento local de threads"
ms.assetid: 071fec79-c701-432b-9970-457344133159
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GT (armazenamento local de thread seguro de fibra de suporte)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Da suporte à segurança de fibra para os dados atribuídos estático usando o armazenamento de thread local, isto é, com `__declspec(thread)`dados atribuídos.  
  
## Sintaxe  
  
```  
/GT  
```  
  
## Comentários  
 Os dados declarados com `__declspec(thread)` são referenciados com uma matriz \(TLS\) de armazenamento de thread local.  A matriz do TLS é uma matriz de endereços que o sistema mantém para cada thread.  Cada endereço nesta matriz de dados do local de armazenamento de thread local.  
  
 Uma fibra é um objeto de peso leve que consiste em uma pilha e em um contexto do registro e pode ser agendada em vários threads.  Uma fibra pode ser executada em qualquer thread.  Como uma fibra pode obter alternado de saída e reiniciado mais tarde em um thread diferente, o endereço da matriz do TLS não deve ser armazenado em cachê ou otimizado como uma subexpressão comuns por uma chamada de função \(consulte a opção de [\/Og \(otimizações globais\)](../../build/reference/og-global-optimizations.md) para obter detalhes\).  **\/GT** evitar tais otimizações.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Otimização** .  
  
4.  Modifique a propriedade de **Habilita Otimizações Seguras para Fibras** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFiberSafeOptimizations%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)