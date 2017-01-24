---
title: "Considera&#231;&#245;es sobre desempenho para interop (C++) | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], considerações sobre desempenho de interoperabilidade (C++)"
  - "interoperabilidade [C++], considerações sobre desempenho"
  - "interoperabilidade [C++], considerações sobre desempenho"
  - "assemblies mistos [C++], considerações sobre desempenho"
  - "invocação de plataforma [C++], interoperabilidade"
ms.assetid: bb9a282e-c3f8-40eb-a2fa-45d80d578932
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Considera&#231;&#245;es sobre desempenho para interop (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico fornece diretrizes para reduzir o efeito transições gerenciados e não gerenciados de interoperabilidade no desempenho de tempo de execução.  
  
 Visual C\+\+ compatível com os mesmos mecanismos de interoperabilidade que outros idiomas do .NET como o Visual Basic e visual C\# \(P\/Invoke\), mas também fornece suporte de interoperabilidade que é específico do Visual C\+\+ interoperabilidade \(C\+\+\).  Para aplicativos de desempenho críticas, é importante compreender as implicações de desempenho de cada técnica de interoperabilidade.  
  
 Independentemente da técnica de interoperabilidade usada, as sequências especiais de transição, thunks chamados, são necessárias para cada vez que as chamadas de função gerenciados uma função não gerenciado e vice\-versa.  Esses thunks são inseridos automaticamente pelo compilador do Visual C\+\+, mas é importante ter em mente que cumulativa, essas transições pode ser cara em termos de desempenho.  
  
## Reduzindo transições  
 Um modo para evitar ou reduzir os custos de thunks de interoperabilidade é a refactor as interfaces envolvidas para reduzir transições gerenciados e não gerenciados.  As melhorias de desempenho dramático podem ser feitas direcionar as interfaces tagarelas, que são aquelas que envolvido frequente chamadas por limite gerenciados e não gerenciados.  Uma função gerenciada que chama uma função não gerenciado em um loop estreito, por exemplo, é uma boa candidata para refactoring.  Se o próprio loop for movido para o lado não gerenciado, ou se uma alternativa à chamada gerenciado não gerenciado é criada \(talvez seja enfileirando dados no lado gerenciado e é marshaling na API não gerenciado de uma vez depois que o loop\), o número de transições pode ser reduzido significativamente.  
  
## P\/Invoke em C\+\+ Interoperabilidade  
 Para linguagens .NET, como o Visual Basic e visual C\#, o método prescrito para interoperar com componentes nativos é P\/Invoke.  Como P\/Invoke tem suporte do .NET Framework, Visual C\+\+ fazê\-lo além disso, mas o Visual C\+\+ também fornece seu próprio suporte à interoperabilidade, que é chamado C\+\+ Interoperabilidade.  C\+\+ Interoperabilidade é preferível P\/Invoke P\/Invoke porque não é do tipo seguro.  No resultado, os erros são reportados primeiro em tempo de execução, mas C\+\+ Interoperabilidade também tem vantagens de desempenho sobre P\/Invoke.  
  
 Ambas as técnicas requerem várias coisas ocorrer sempre que as chamadas de função gerenciados uma função não gerenciada:  
  
-   Os argumentos da chamada de função marshaling de CLR para tipos nativos.  
  
-   Um thunk gerenciar\-à\-não gerenciado é executado.  
  
-   A função não gerenciado é chamada \(usando as versões nativos dos argumentos\).  
  
-   Um thunk não gerenciado\-à\-gerenciado é executado.  
  
-   O tipo de retorno e “out” ou “no, out” marshaling de argumentos nativos para tipos CLR.  
  
 Thunks gerenciados e não gerenciados são necessários para que o funcione de interoperabilidade possível, mas o marshaling de dados que é necessário dependem dos tipos de dados envolvidos, a assinatura da função, e como os dados será usado.  
  
 Marshaling de dados executado por C\+\+ Interoperabilidade é a forma mais simples possível o: os parâmetros são copiados apenas por limite gerenciados e não gerenciados em uma forma de bit a bit; nenhuma transformação é executada de qualquer.  Para P\/Invoke, isso só ocorrerá se todos os parâmetros são simples, tipos blittables.  Se não, P\/Invoke executa etapas muito robustas para converter cada parâmetro gerenciado em um tipo nativo apropriado, e vice\-versa se os argumentos forem marcados como “out”, ou no, “out”.  
  
 Ou seja C\+\+ Interoperabilidade usa o método mais rápido possível que o marshaling de dados, enquanto P\/Invoke usa o método mais robusto.  Isso significa que C\+\+ Interoperabilidade \(em uma forma comum para C\+\+\) fornece desempenho ótimo por padrão, o e o programador é responsável para solucionar os casos em que esse comportamento não é seguro ou apropriado.  
  
 C\+\+ Interoperabilidade em virtude disso requer que o marshaling de dados deve ser fornecido explicitamente, mas a vantagem é que o programador está livre o decidir que é apropriado, dada a natureza de dados, e como ele deve ser usada.  Além disso, embora o comportamento do marshaling de dados de P\/Invoke pode ser alterado em personalizado a um grau, C\+\+ Interoperabilidade permite os dados que o marshaling para ser personalizado em uma base de atendimento\-por\- chamada.  Isso não é possível com P\/Invoke.  
  
 Para obter mais informações sobre C\+\+ Interoperabilidade, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)