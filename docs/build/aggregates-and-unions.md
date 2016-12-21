---
title: "Agrega&#231;&#245;es e uni&#245;es | Microsoft Docs"
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
  - "agregações [C++], e uniões"
ms.assetid: 859fc211-b111-4f12-af98-de78e48f9b92
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Agrega&#231;&#245;es e uni&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Outros tipos como matrizes, estruturas, e uniões têm um requisitos mais restritos de alinhamento que assegurem a agregação consistente e armazenamento e recuperação de dados de união.  Aqui estão as definições para a matriz, a estrutura, e a união:  
  
 Matriz  
 Contém um grupo ordenado de objetos de dados adjacentes.  Cada objeto é chamado um elemento.  Todos os elementos de uma matriz têm o mesmo tamanho e o tipo de dados.  
  
 Estrutura  
 Contém um grupo ordenado de objetos de dados.  Ao contrário dos elementos de uma matriz, os objetos de dados em uma estrutura podem ter tipos de dados e tamanhos diferentes.  Cada objeto de dados em uma estrutura é chamado um membro.  
  
 União  
 Um objeto que contém qualquer de um conjunto de membros nomeados.  Os membros do conjunto chamado podem ser de qualquer tipo.  O armazenamento atribuído para uma união é igual ao armazenamento necessário para o membro maior da união, mais qualquer preenchimento necessário para o alinhamento.  
  
 A tabela a seguir mostra o alinhamento fortemente sugerido para os membros escalares de uniões e estruturas.  
  
||||  
|-|-|-|  
|Tipo escalar|Tipo de dados de C|Alinhamento necessário|  
|**INT8**|`char`|Byte|  
|**UINT8**|`unsigned char`|Byte|  
|**INT16**|**short**|O Word|  
|**UINT16**|**unsigned short**|O Word|  
|**INT32**|**int, long**|Palavra composta|  
|**UINT32**|**unsigned int, unsigned long**|Palavra composta|  
|**INT64**|`__int64`|Quadword|  
|**UINT64**|**unsigned \_\_int64**|Quadword|  
|**FP32 \(precisão única\)**|**float**|Palavra composta|  
|**FP64 \(precisão dupla\)**|**double**|Quadword|  
|**PONTEIRO**|**\***|Quadword|  
|`__m64`|**estrutura \_\_m64**|Quadword|  
|`__m128`|**estrutura \_\_m128**|Octaword|  
  
 As seguintes regras agregadas de alinhamento se aplicam:  
  
-   O alinhamento de uma matriz é o mesmo que o alinhamento de um dos elementos da matriz.  
  
-   O alinhamento de início de uma estrutura ou uma união é o alinhamento máximo de qualquer membro individual.  Cada membro na estrutura ou de união deve ser colocado no alinhamento apropriado como definido na tabela anterior, que pode exigir o preenchimento join implícito, dependendo do membro anterior.  
  
-   O tamanho da estrutura deve ser um várias integral do alinhamento, que pode exigir o preenchimento após o último membro.  Como estruturas e uniões pode ser agrupados em matrizes, cada elemento da matriz de uma estrutura ou uma união deve iniciar e terminam no alinhamento apropriado determinado anteriormente.  
  
-   É possível alinhar dados de modo que ser maior do que os requisitos de alinhamento como as regras anteriores são mantidas.  
  
-   Um compilador individual pode ajustar a caixa de uma estrutura por motivo de tamanho.  Por exemplo [\/Zp \(alinhamento de membro do Struct\)](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md) permite ajustando a caixa estruturas.  
  
## Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)