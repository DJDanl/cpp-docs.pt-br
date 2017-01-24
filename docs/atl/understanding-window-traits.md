---
title: "A janela de tra&#231;os entendendo | Microsoft Docs"
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
  - "traços da janela"
ms.assetid: c90cf850-9e91-49da-9cf3-ad4efb30347d
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A janela de tra&#231;os entendendo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes dos traços da janela fornecem um método simples para padronizar os estilos usados para a criação de um objeto da janela de ATL.  Os traços da janela são aceitos como parâmetros do modelo por [CWindowImpl](../Topic/CWindowImpl%20Class.md) e outras classes da janela de ATL como uma maneira de fornecer estilos de janela padrão no nível de classe.  
  
 Se o criador de uma instância da janela não fornece estilos explicitamente na chamada a [Criar](../Topic/CWindowImpl::Create.md), você pode usar uma classe dos traços para garantir que a janela ainda ser criada com os estilos corretos.  Você ainda pode garantir que determinados estilos são definidos para todas as instâncias de classe da janela para permitir que outros estilos ser definido em uma base por instância.  
  
## Modelos dos traços da janela de ATL  
 ATL fornece dois modelos dos traços da janela que permitem que você defina os estilos padrão em tempo de compilação que usam os parâmetros de modelo.  
  
|Classe|Descrição|  
|------------|---------------|  
|[CWinTraits](../atl/reference/cwintraits-class.md)|Use esse modelo quando você deseja fornecer os estilos de janela padrão que serão usados somente quando nenhum outro estilo é especificado na chamada a **Criar**.  Os estilos fornecidos em tempo de execução têm precedência sobre os estilos definidos em tempo de compilação.|  
|[CWinTraitsOR](../atl/reference/cwintraitsor-class.md)|Use esta classe quando você deseja especificar os estilos que sempre devem ser definidas para a classe da janela.  Os estilos fornecidos em tempo de execução são combinados com os estilos definidos em tempo de compilação usando o operador OR bit a bit.|  
  
 Além de esses modelos, ATL fornece um número de especializações predefinidas do modelo de `CWinTraits` para combinações de uso geral de estilos de janela.  Consulte a documentação de referência de [CWinTraits](../atl/reference/cwintraits-class.md) para detalhes completos.  
  
## Traços personalizados da janela  
 A situação improvável que especializar um dos modelos oferecidos por ATL não é suficiente e você precisará criar seus próprios traços classe, você precisa criar uma classe que implementa duas funções estáticas: `GetWndStyle` e **GetWndStyleEx**:  
  
 [!code-cpp[NVC_ATL_Windowing#68](../atl/codesnippet/CPP/understanding-window-traits_1.h)]  
  
 Cada uma de essas funções será passada qualquer valor de estilo em tempo de execução que pode usar para gerar um novo valor de estilo.  Se sua classe dos traços da janela está sendo usada como o argumento do modelo para uma classe de janela de ATL, os valores de estilo passados a essas funções estáticas serão o que foram passados como argumentos de estilo a [Criar](../Topic/CWindowImpl::Create.md).  
  
## Consulte também  
 [Classes de janela](../Topic/ATL%20Window%20Classes.md)