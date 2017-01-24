---
title: "Namespace Concurrency::direct3d | Microsoft Docs"
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
  - "amp/Concurrency::direct3d"
  - "amprt/Concurrency::direct3d"
  - "amp_short_vectors/Concurrency::direct3d"
  - "amp_graphics/Concurrency::direct3d"
  - "amp_math/Concurrency::direct3d"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Namespace direct3d"
ms.assetid: 9566a2f1-4d5f-43e4-a3ac-676643d38420
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Concurrency::direct3d
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O namespace `direct3d` fornece funções que suportam a interoperabilidade D3D.  Permite o uso contínuo de recursos de D3D para cálculos no código AMP bem como permite o uso de recursos criados no AMP no código D3D, sem criar cópias intermediárias redundantes.  Você pode acelerar de forma crescente as seções intensas de cálculo dos seus aplicativos DirectX usando o C\+\+ AMP, e usar o D3D API em dados gerados pelos cálculos AMP.  
  
## Sintaxe  
  
```  
namespace direct3d;  
```  
  
## Membros  
  
### Classes  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe scoped\_d3d\_access\_lock](../Topic/scoped_d3d_access_lock%20Class.md)|Um wrapper de RAII para um bloqueio de acesso de D3D em um objeto de `accelerator_view`.|  
  
### Estruturas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura adopt\_d3d\_access\_lock\_t](../../../parallel/amp/reference/adopt-d3d-access-lock-t-structure.md)|O tipo de marca para indicar o bloqueio de acesso de D3D deve ser adotado em vez de adquirido.|  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função abs](../Topic/abs%20Function.md)|Retorna o valor absoluto do argumento|  
|[Função clamp](../Topic/clamp%20Function.md)|Sobrecarregado.  Redimensiona \_X para caber no intervalo especificado \_Min e \_Max|  
|[Função countbits](../Topic/countbits%20Function.md)|Conta o número de bits definidos em \_X|  
|[Função create\_accelerator\_view](../Topic/create_accelerator_view%20Function.md)|Criar um [Classe accelerator\_view](../Topic/accelerator_view%20Class.md) de um ponteiro para a interface de dispositivo Direct3D|  
|[Função d3d\_access\_lock](../Topic/d3d_access_lock%20Function.md)|Adquire um bloqueio em um accelerator\_view com a finalidade de executar operações de D3D de forma segura em recursos compartilhados com o accelerator\_view|  
|[Função d3d\_access\_try\_lock](../Topic/d3d_access_try_lock%20Function.md)|Tentativa de adquirir o bloqueio de acesso D3D em um accelerator\_view sem bloqueio.|  
|[Função d3d\_access\_unlock](../Topic/d3d_access_unlock%20Function.md)|Liberar o bloqueio de acesso de D3D no accelerator\_view determinado.|  
|[Função firstbithigh](../Topic/firstbithigh%20Function.md)|Obtém o local do primeiro bit definido em \_X, partindo do bit de ordem mais alta e segue descendo|  
|[Função firstbitlow](../Topic/firstbitlow%20Function.md)|Obtém o local do primeiro bit definido em \_X, partindo do bit de menor ordem em direção aos de maior ordem|  
|[Função get\_buffer](../Topic/get_buffer%20Function.md)|Obtém a interface do buffer D3D subjacente a uma matriz.|  
|[Função imax](../Topic/imax%20Function.md)|Compara dois valores, retornando o valor que for maior.|  
|[Função imin](../Topic/imin%20Function.md)|Compara dois valores, retornando o valor que for menor.|  
|[Função is\_timeout\_disabled](../Topic/is_timeout_disabled%20Function.md)|Retorna um sinalizador booleano que indica se o tempo limite está desativado para o accelerator\_view especificado.|  
|[Função mad](../Topic/mad%20Function.md)|Sobrecarregado.  Executa uma operação aritmética multiplicação\/adição em três argumentos: \_X \* \_Y \+ \_Z|  
|[Função make\_array](../Topic/make_array%20Function.md)|Criar uma matriz a partir de um ponteiro para interface do buffer D3D.|  
|[Função noise](../Topic/noise%20Function.md)|Gera um valor aleatório usando o algoritmo de ruído de Perlin|  
|[Função radians](../Topic/radians%20Function.md)|Converte \_X de graus para radianos|  
|[Função rcp](../Topic/rcp%20Function.md)|Calcula um recíproco rápido e aproximado do argumento|  
|[Função reversebits](../Topic/reversebits%20Function.md)|Inverte a ordem dos bits em \_X|  
|[Função saturate](../Topic/saturate%20Function.md)|Aperta o \_X dentro do intervalo de 0 a 1|  
|[Função sign](../Topic/sign%20Function.md)|Sobrecarregado.  Retorna o sinal do argumento|  
|[Função smoothstep](../Topic/smoothstep%20Function.md)|Retorna uma interpolação suave de Hermite entre 0 e 1, se \_X estiver no intervalo \[\_Min, \_Max\].|  
|[Função step](../Topic/step%20Function.md)|Compara dois valores, retornando 0 ou 1 baseado em qual valor é maior|  
|[Função umax](../Topic/umax%20Function.md)|Compara dois valores não assinados, retornando o valor que for maior.|  
|[Função umin](../Topic/umin%20Function.md)|Compara dois valores não assinados, retornando o valor que for menor.|  
  
## Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)