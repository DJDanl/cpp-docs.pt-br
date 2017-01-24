---
title: "Classe de CArray | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], classes"
  - "Classe de CArray"
  - "classes de coleção, baseado modelo-"
  - "modelos, classes de coleção"
ms.assetid: fead8b00-4cfd-4625-ad0e-251df62ba92f
caps.latest.revision: 33
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta matrizes que são como matrizes de C, mas pode crescer e reduz dinamicamente como necessário.  
  
## Sintaxe  
  
```  
template < class TYPE, class ARG_TYPE = const TYPE& >   
class CArray :   
   public CObject  
```  
  
#### Parâmetros  
 `TYPE`  
 O parâmetro do modelo que especifica o tipo de objetos armazenados na matriz.  `TYPE` é um parametro que é retornado por `CArray`.  
  
 `ARG` *\_* `TYPE`  
 O parâmetro do modelo que especifica o tipo de argumento que é usada para acessar objetos armazenados na matriz.  Geralmente uma referência a `TYPE`.  `ARG_TYPE` é um parametro que é passado para `CArray`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArray::CArray](../Topic/CArray::CArray.md)|Constrói uma matriz vazia.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArray::Add](../Topic/CArray::Add.md)|Adiciona um elemento ao final da matriz; aumenta a matriz se necessário.|  
|[CArray::Append](../Topic/CArray::Append.md)|Acrescenta uma matriz a outra matriz; aumenta a matriz se necessário|  
|[CArray::Copy](../Topic/CArray::Copy.md)|Copia uma matriz a outra matriz; aumenta a matriz se necessário.|  
|[CArray::ElementAt](../Topic/CArray::ElementAt.md)|Retorna uma referência temporária ao ponteiro de elemento dentro da matriz.|  
|[CArray::FreeExtra](../Topic/CArray::FreeExtra.md)|Qualquer libera a memória não usado acima do limite superior atual.|  
|[CArray::GetAt](../Topic/CArray::GetAt.md)|Retorna o valor em um índice especificado.|  
|[CArray::GetCount](../Topic/CArray::GetCount.md)|Obtém o número de elementos em esta matriz.|  
|[CArray::GetData](../Topic/CArray::GetData.md)|Permite acesso aos elementos na matriz.  Pode ser **NULO**.|  
|[CArray::GetSize](../Topic/CArray::GetSize.md)|Obtém o número de elementos em esta matriz.|  
|[CArray::GetUpperBound](../Topic/CArray::GetUpperBound.md)|Retorna o índice válido maior.|  
|[CArray::InsertAt](../Topic/CArray::InsertAt.md)|Insere elemento \(ou todos os elementos em outros matriz\) em um índice especificado.|  
|[CArray::IsEmpty](../Topic/CArray::IsEmpty.md)|Determina se a matriz está vazia.|  
|[CArray::RemoveAll](../Topic/CArray::RemoveAll.md)|Remove todos os elementos da matriz.|  
|[CArray::RemoveAt](../Topic/CArray::RemoveAt.md)|Remove um elemento em um índice específico.|  
|[CArray::SetAt](../Topic/CArray::SetAt.md)|Defina o valor para um índice dado; matriz não permitida crescer.|  
|[CArray::SetAtGrow](../Topic/CArray::SetAtGrow.md)|Defina o valor para um índice dado; aumenta a matriz se necessário.|  
|[CArray::SetSize](../Topic/CArray::SetSize.md)|Define o número de elementos a serem contidos em esta matriz.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArray::operator](../Topic/CArray::operator.md)|Obtém ou define o elemento no índice especificado.|  
  
## Comentários  
 Matriz de índices sempre início na posição 0.  Você pode decidir se corrigir o limite superior ou ativar a matriz para expandir quando você adiciona elementos após o limite atual.  A memória é atribuída continuamente ao limite superior, mesmo se alguns elementos são nulos.  
  
> [!NOTE]
>  A maioria dos métodos de redimensionamento um objeto de `CArray` ou para adicionar elementos uso [memcpy\_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md) aos elementos de animação.  Este é um problema pois `memcpy_s` não é compatível com qualquer objeto que exigem o construtor ser chamados.  Se os itens em `CArray` não são compatíveis com `memcpy_s`, você deve criar uma nova `CArray` de tamanho apropriado.  Você deve usar [CArray::Copy](../Topic/CArray::Copy.md) e [CArray::SetAt](../Topic/CArray::SetAt.md) para preencher a nova matriz porque esses métodos usam um operador de atribuição em vez de `memcpy_s`.  
  
 Como com matriz de energia AC, última hora de acesso para um elemento indexado `CArray` são constantes e são independentes do tamanho da matriz.  
  
> [!TIP]
>  Antes de usar uma matriz, use [SetSize](../Topic/CArray::SetSize.md) para estabelecer o tamanho e atribuir a memória para ele.  Se você não usar `SetSize`, adicione os elementos a sua matriz freqüentemente faz com que ele manipule a ser realocada e copiado.  A realocação freqüentes e copiar e são não podem fragmentar a memória.  
  
 Se você precisar de um despejo dos elementos individuais em uma matriz, você deve definir o tamanho do objeto de [CDumpContext](../../mfc/reference/cdumpcontext-class.md) a 1 ou maior.  
  
 Determinadas funções de membro de essa classe chamam funções auxiliares globais que devem ser personalizadas para a maioria dos usos da classe de `CArray` .  Consulte o tópico [Auxiliares de classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção de macros e de Globais MFC.  
  
 A derivação da classe da matriz é como a derivação da lista.  
  
 Para obter mais informações sobre como usar `CArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CArray`  
  
## Requisitos  
 `Header:` afxtempl.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CObArray](../../mfc/reference/cobarray-class.md)   
 [Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)