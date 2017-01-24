---
title: "Type Forwarding (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "type forwarding, Visual C++"
ms.assetid: ae730b69-0c27-41cc-84e1-3132783866ea
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Type Forwarding (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*O encaminhamento de tipo* permite que você mova um tipo de assembly A um assembly \(\) em outro assembly assembly \(B\), de modo que, não é necessário recompilar os clientes que consomem o assembly Para.  
  
## Todas as Plataformas  
 Esse recurso não tem suporte em todo o tempo de execução.  
  
## Tempo de execução do windows  
 Esse recurso não tem suporte em [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 O exemplo de código a seguir demonstra como usar a transmissão do tipo.  
  
### Sintaxe  
  
```  
#using "new.dll"  
[assembly:TypeForwardedTo(type::typeid)];  
```  
  
### Parâmetros  
 `new`  
 O assembly no qual você está movendo a definição do tipo.  
  
 `type`  
 A definição de tipo cujo você está movendo em outro assembly.  
  
### Comentários  
 Depois que o é fornecido de um componente assembly \(\) e estão sendo usados por aplicativos cliente, você pode usar a transmissão do tipo para mover um tipo de componente \(assembly\) em outro assembly, envia o componente atualizado \(e alguns assemblies adicionais necessários\), e os aplicativos cliente ainda funcionarão sem ser recompilado.  
  
 Tipo que encaminha apenas os trabalhos para os componentes referenciados pelos aplicativos existentes.  Quando você recria um aplicativo, deve haver referências apropriados do assembly para tipos usados no aplicativo.  
  
 Para encaminhar um tipo tipo \(A\) de um assembly, você deve adicionar o atributo de `TypeForwardedTo` para esse tipo, bem como uma referência de assembly.  O assembly referenciado deve conter um dos seguintes:  
  
-   A definição do tipo Para.  
  
-   Um atributo de `TypeForwardedTo` para o tipo Para, bem como uma referência de assembly.  
  
 Exemplos dos tipos que podem ser encaminhados incluem:  
  
-   classes de referência  
  
-   classes de valor  
  
-   enum  
  
-   interfaces  
  
 Você não pode encaminhar os seguintes tipos:  
  
-   Tipos genéricos  
  
-   Tipos nativos  
  
-   Tipos aninhados \(se desejar encaminhar um tipo aninhado, você deve encaminhar o tipo incluindo\)  
  
 Você pode encaminhar um tipo em um assembly criado em qualquer linguagem que se destinam Common Language Runtime.  
  
 Assim, se um arquivo de código\-fonte que foi usado para criar o assembly A.dll contém uma definição de tipo \(`ref class MyClass`\), e você quiser mover a definição de tipo ao assembly B.dll, você:  
  
1.  Mover a definição de tipo de `MyClass` a um arquivo de código\-fonte usado para criar B.dll.  
  
2.  Compile o assembly B.dll  
  
3.  Excluir a definição de tipo de `MyClass` do código\-fonte usado para criar A.dll, e substitua pelo seguinte:  
  
    ```  
    #using "B.dll"  
    [assembly:TypeForwardedTo(MyClass::typeid)];  
    ```  
  
4.  Compile o assembly A.dll.  
  
5.  Use A.dll sem recompilar aplicativos cliente.  
  
### Requisitos  
 Opção do compilador: **\/clr**