---
title: "Auxiliares da classe de coleção | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.classes
dev_langs:
- C++
helpviewer_keywords:
- DestructElements function
- ConstructElements function
- SerializeElements function
- collection classes, helper functions
- helper functions collection class
ms.assetid: bc3a2368-9edd-4748-9e6a-13cba79517ca
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: d2649ef9c8b0320a94ec28a2341baa0f768b07d0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="collection-class-helpers"></a>Auxiliares da classe de coleção
As classes de coleção `CMap`, `CList`, e `CArray` usar funções auxiliares global modelado para esses fins como comparação, copiar e serializando elementos. Como parte de sua implementação de classes com base em `CMap`, `CList`, e `CArray`, você deve substituir essas funções conforme necessário com as versões adaptadas para o tipo de dados armazenados no seu mapa, lista ou matriz. Para obter informações sobre substituição de funções auxiliares como `SerializeElements`, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md). Observe que **ConstructElements** e **DestructElements** foram substituídos.  
  
 A biblioteca Microsoft Foundation Class fornece as seguintes funções globais no afxtempl.h para ajudá-lo a personalizar suas classes de coleção:  
  
### <a name="collection-class-helpers"></a>Auxiliares da classe de coleção  
  
|||  
|-|-|  
|[CompareElements](#compareelements)|Indica se os elementos são iguais.|  
|[CopyElements](#copyelements)|Copia os elementos de um array para outro.|  
|[DumpElements](#dumpelements)|Fornece a saída de diagnóstico orientado por fluxo.|  
|[HashKey](#hashkey)|Calcula uma chave de hash.|  
|[SerializeElements](#serializeelements)|Armazena ou recupera os elementos de ou para um arquivo morto.|  
  
##  <a name="compareelements"></a>CompareElements  
 Chamados diretamente por [CList::Find] (clist class.md not_found.md # #clist__find e indiretamente por [cmap__lookup](cmap-class.md#lookup) e [[cmap__operator]](cmap-class.md#operator_at).  
  
```   
template<class TYPE, class ARG_TYPE>  
BOOL AFXAPI  
CompareElements(
    const TYPE* pElement1,  
    const ARG_TYPE* pElement2);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 O tipo do primeiro elemento a ser comparado.  
  
 `pElement1`  
 Ponteiro para o primeiro elemento a ser comparado.  
  
 `ARG_TYPE`  
 O tipo do segundo elemento a ser comparado.  
  
 `pElement2`  
 Ponteiro para o segundo elemento a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto apontado por `pElement1` é igual ao objeto apontado por `pElement2`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `CMap` chama o uso de `CMap` parâmetros de modelo *chave* e `ARG_KEY`.  
  
 A implementação padrão retorna o resultado da comparação de * \*pElement1* e * \*pElement2*. Substitua essa função para que ele compara os elementos de uma maneira que seja apropriado para seu aplicativo.  
  
 A linguagem C++ define o operador de comparação ( `==`) para tipos simples ( `char`, `int`, **float**e assim por diante), mas não define um operador de comparação para classes e estruturas. Se você quiser usar `CompareElements` ou para instanciar uma das classes de coleção que usa, você deve definir o operador de comparação ou sobrecarregar `CompareElements` com uma versão que retorna os valores apropriados.  
  
### <a name="requirements"></a>Requisitos  
   **Cabeçalho:** afxtempl.h   
  
##  <a name="copyelements"></a>CopyElements  
 Essa função é chamada diretamente por [CArray::Append](carray-class.md#append) e [CArray::Copy](carray-class.md#copy).  
  
```   
template<class TYPE>  
void AFXAPI CopyElements(
    TYPE* pDest,  
    const TYPE* pSrc,  
    INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Parâmetro de modelo especificando o tipo de elementos a serem copiados.  
  
 `pDest`  
 Ponteiro para o destino onde os elementos serão copiados.  
  
 `pSrc`  
 Ponteiro para a fonte dos elementos a serem copiados.  
  
 `nCount`  
 Número de elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão usa o operador de atribuição simples ( ** = ** ) para executar a operação de cópia. Se o tipo que está sendo copiado não tem um operador sobrecarregado =, a implementação padrão faz uma cópia bit a bit.  
  
 Para obter informações sobre como implementar essa e outras funções auxiliares, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h  
  
##  <a name="dumpelements"></a>DumpElements  
 Fornece a saída de diagnóstico orientada por fluxo na forma de texto para os elementos de sua coleção quando for substituído.  
  
```   
template<class TYPE>  
void  AFXAPI DumpElements(
    CDumpContext& dc,  
    const TYPE* pElements,  
    INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 Contexto para despejar os elementos de despejo.  
  
 *TIPO*  
 Especificar o tipo dos elementos de parâmetro de modelo.  
  
 `pElements`  
 Ponteiro para os elementos a ser despejado.  
  
 `nCount`  
 Número de elementos a ser despejado.  
  
### <a name="remarks"></a>Comentários  
 O **CArray::Dump**, **CList::Dump**, e **CMap::Dump** funções chamá-lo se a profundidade do despejo é maior que 0.  
  
 A implementação padrão não faz nada. Se os elementos da coleção são derivados de `CObject`, sua substituição normalmente irá iterar através de elementos da coleção, chamando `Dump` para cada elemento por sua vez.  
  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h  
  
##  <a name="hashkey"></a>HashKey  
 Calcula um valor de hash para a chave especificada.  
  
```  
template<class ARG_KEY>  
AFX_INLINE UINT AFXAPI HashKey(ARG_KEY  key); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_KEY`  
 Parâmetro de modelo especificando o tipo de dados usado para acessar as chaves do mapa.  
  
 `key`  
 A chave cujo valor de hash é calculado.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor de hash da chave.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada diretamente por [CMap::RemoveKey](cmap-class.md#removekey) e indiretamente por [CMap::Lookup](cmap-class.md#lookup) e [[CMap::Operator]](cmap-class.md#operator_at).
  
 A implementação padrão cria um valor de hash, alternando `key` à direita por quatro posições. Substitua essa função para que ele retorna valores de hash apropriado para seu aplicativo.  
  
### <a name="example"></a>Exemplo
 ```cpp  
template <> UINT AFXAPI HashKey(unsigned __int64 key)
{
   // Generate the hash value by XORing the lower 32 bits of the number 
   // with the upper 32 bits
   return(UINT(key) ^ UINT(key >> 32));
}
 ```
 
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h 
  
##  <a name="serializeelements"></a>SerializeElements  
 [CArray](carray-class.md), [CList](clist-class.md), e [CMap](cmap-class.md) chamar essa função para serializar elementos.  
  
```   
template<class TYPE>  
void AFXAPI SerializeElements(CArchive& ar, TYPE* pElements, INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO*  
 Especificar o tipo dos elementos de parâmetro de modelo.  
  
 `ar`  
 Um objeto de arquivo morto para arquivar para ou de.  
  
 `pElements`  
 Ponteiro para os elementos que estão sendo arquivados.  
  
 `nCount`  
 Número de elementos que estão sendo arquivados  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não tem um bit a bit de leitura ou gravação.  
  
 Para obter informações sobre como implementar essa e outras funções auxiliares, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo no artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
 
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h 
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [Classe CMap](cmap-class.md)   
 [Classe CList](clist-class.md)   
 [Classe CArray](carray-class.md)
