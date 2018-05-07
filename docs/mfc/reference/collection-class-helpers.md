---
title: Auxiliares da classe de coleção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.classes
dev_langs:
- C++
helpviewer_keywords:
- DestructElements function
- ConstructElements function
- SerializeElements function
- collection classes [MFC], helper functions
- helper functions collection class [MFC]
ms.assetid: bc3a2368-9edd-4748-9e6a-13cba79517ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d00d78acf7ddf8cfa27e117cbcdbbb00c7d6fa6b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="collection-class-helpers"></a>Auxiliares da classe de coleção
As classes de coleção `CMap`, `CList`, e `CArray` usar funções de modelo auxiliar globais para esses fins de comparação, cópia e serializando elementos. Como parte de sua implementação de classes com base em `CMap`, `CList`, e `CArray`, você deve substituir essas funções conforme necessário com as versões de acordo com o tipo de dados armazenados em seu mapa, lista ou matriz. Para obter informações sobre substituição de funções auxiliares, como `SerializeElements`, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../../mfc/how-to-make-a-type-safe-collection.md). Observe que **ConstructElements** e **DestructElements** foram preteridos.  
  
 A biblioteca Microsoft Foundation Class fornece as seguintes funções globais no afxtempl.h para ajudá-lo a personalizar suas classes de coleção:  
  
### <a name="collection-class-helpers"></a>Auxiliares da classe de coleção  
  
|||  
|-|-|  
|[CompareElements](#compareelements)|Indica se os elementos são os mesmos.|  
|[CopyElements](#copyelements)|Elementos de cópias de um array para outro.|  
|[DumpElements](#dumpelements)|Fornece a saída de diagnóstica orientada por fluxo.|  
|[HashKey](#hashkey)|Calcula uma chave de hash.|  
|[SerializeElements](#serializeelements)|Armazena ou recupera os elementos de ou para um arquivo morto.|  
  
##  <a name="compareelements"></a>  CompareElements  
 Chamado diretamente por [CList::Find] (clist class.md not_found.md # #clist__find e indiretamente por [cmap__lookup](cmap-class.md#lookup) e [cmap__operator &#91; &#93; ](cmap-class.md#operator_at).  
  
```   
template<class TYPE, class ARG_TYPE>  
BOOL AFXAPI  
CompareElements(
    const TYPE* pElement1,  
    const ARG_TYPE* pElement2);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 O tipo do primeiro elemento a ser comparado.  
  
 `pElement1`  
 Ponteiro para o primeiro elemento a ser comparado.  
  
 `ARG_TYPE`  
 O tipo do segundo elemento a ser comparado.  
  
 `pElement2`  
 Ponteiro para o segundo elemento a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto apontado pela `pElement1` é igual ao objeto apontado pela `pElement2`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `CMap` chama o uso de `CMap` parâmetros de modelo *chave* e `ARG_KEY`.  
  
 A implementação padrão retorna o resultado da comparação de  *\*pElement1* e  *\*pElement2*. Substitua essa função para que ele se compara os elementos de uma maneira que seja apropriado para seu aplicativo.  
  
 A linguagem C++ define o operador de comparação ( `==`) para tipos simples ( `char`, `int`, **float**, e assim por diante), mas não define um operador de comparação para classes e estruturas. Se você quiser usar `CompareElements` ou para criar uma instância de uma das classes de coleção que usa, você deve definir o operador de comparação ou sobrecarregar `CompareElements` com uma versão que retorna os valores apropriados.  
  
### <a name="requirements"></a>Requisitos  
   **Cabeçalho:** afxtempl.h   
  
##  <a name="copyelements"></a>  CopyElements  
 Essa função é chamada diretamente por [CArray::Append](carray-class.md#append) e [CArray::Copy](carray-class.md#copy).  
  
```   
template<class TYPE>  
void AFXAPI CopyElements(
    TYPE* pDest,  
    const TYPE* pSrc,  
    INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo de elementos a serem copiados.  
  
 `pDest`  
 Ponteiro para o destino onde os elementos serão copiados.  
  
 `pSrc`  
 Ponteiro para a fonte dos elementos a serem copiados.  
  
 `nCount`  
 Número de elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão usa o operador de atribuição simples ( **=** ) para executar a operação de cópia. Se o tipo que está sendo copiado não tiver um operador sobrecarregado =, em seguida, a implementação padrão realiza uma cópia de bit a bit.  
  
 Para obter informações sobre como implementar essa e outras funções de auxiliar, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h  
  
##  <a name="dumpelements"></a>  DumpElements  
 Fornece a saída de diagnóstica orientada por fluxo em formato de texto para os elementos da sua coleção quando é substituído.  
  
```   
template<class TYPE>  
void  AFXAPI DumpElements(
    CDumpContext& dc,  
    const TYPE* pElements,  
    INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 Despejo de contexto para elementos de despejo.  
  
 *TIPO DE*  
 Especifica o tipo dos elementos de parâmetro de modelo.  
  
 `pElements`  
 Ponteiro para os elementos para ser despejados.  
  
 `nCount`  
 Número de elementos a ser despejados.  
  
### <a name="remarks"></a>Comentários  
 O **CArray::Dump**, **CList::Dump**, e **CMap::Dump** funções chamá-lo se a profundidade do despejo for maior que 0.  
  
 A implementação padrão não fará nada. Se os elementos de sua coleção são derivados de `CObject`, sua substituição normalmente irá iterar por meio de elementos da coleção, chamando `Dump` para cada elemento por sua vez.  
  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h  
  
##  <a name="hashkey"></a>  HashKey  
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
 Essa função é chamada diretamente por [CMap::RemoveKey](cmap-class.md#removekey) e indiretamente por [CMap::Lookup](cmap-class.md#lookup) e [CMap::Operator &#91; &#93; ](cmap-class.md#operator_at).
  
 A implementação padrão cria um valor de hash com a mudança `key` direita por quatro posições. Substitua essa função para que ele retorna valores de hash apropriado para seu aplicativo.  
  
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
  
##  <a name="serializeelements"></a>  SerializeElements  
 [CArray](carray-class.md), [CList](clist-class.md), e [CMap](cmap-class.md) chamar esta função para serializar os elementos.  
  
```   
template<class TYPE>  
void AFXAPI SerializeElements(CArchive& ar, TYPE* pElements, INT_PTR nCount);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo dos elementos de parâmetro de modelo.  
  
 `ar`  
 Um objeto de arquivo morto para arquivar para ou do.  
  
 `pElements`  
 Ponteiro para os elementos que estão sendo arquivados.  
  
 `nCount`  
 Número de elementos que estão sendo arquivadas  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não tem um bit a bit de leitura ou gravação.  
  
 Para obter informações sobre como implementar essa e outras funções de auxiliar, consulte o artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo no artigo [coleções: como fazer uma coleção fortemente tipada](../how-to-make-a-type-safe-collection.md).  
 
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxtempl.h 
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [Classe CMap](cmap-class.md)   
 [Classe CList](clist-class.md)   
 [Classe CArray](carray-class.md)