---
title: Classe CTypedPtrMap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTypedPtrMap
- AFXTEMPL/CTypedPtrMap
- AFXTEMPL/CTypedPtrMap::GetNextAssoc
- AFXTEMPL/CTypedPtrMap::Lookup
- AFXTEMPL/CTypedPtrMap::RemoveKey
- AFXTEMPL/CTypedPtrMap::SetAt
dev_langs:
- C++
helpviewer_keywords:
- type-safe collections
- template classes, CTypedPtrMap class
- maps
- CTypedPtrMap class
- pointer maps
ms.assetid: 9f377385-c6e9-4471-8b40-8fe220c50164
caps.latest.revision: 23
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
ms.openlocfilehash: 919d751c6ffe4b10ffad047f1b6be832bf49a1af
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ctypedptrmap-class"></a>Classe CTypedPtrMap
Fornece um "wrapper" para objetos das classes de mapa de ponteiro de tipo seguro `CMapPtrToPtr`, `CMapPtrToWord`, `CMapWordToPtr`, e `CMapStringToPtr`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class BASE_CLASS, class KEY, class VALUE>  
class CTypedPtrMap : public BASE_CLASS  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Classe base da classe map ponteiro tipado; deve ser uma classe de mapa do ponteiro ( `CMapPtrToPtr`, `CMapPtrToWord`, `CMapWordToPtr`, ou `CMapStringToPtr`).  
  
 `KEY`  
 Classe do objeto usado como a chave para o mapa.  
  
 `VALUE`  
 Classe do objeto armazenado no mapa.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTypedPtrMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento de iteração.|  
|[CTypedPtrMap::Lookup](#lookup)|Retorna um `KEY` com base em um `VALUE`.|  
|[CTypedPtrMap::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|  
|[CTypedPtrMap::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CTypedPtrMap::operator]](#operator_at)|Insere um elemento no mapa.|  
  
## <a name="remarks"></a>Comentários  
 Quando você usa `CTypedPtrMap`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.  
  
 Porque todos os `CTypedPtrMap` funções embutidas, uso deste modelo não afeta significativamente o tamanho ou a velocidade do seu código.  
  
 Para obter mais informações sobre como usar o `CTypedPtrMap`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `BASE_CLASS`  
  
 `CTypedPtrMap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtempl.h  
  
##  <a name="getnextassoc"></a>CTypedPtrMap::GetNextAssoc  
 Recupera o elemento de mapa em `rNextPosition`, em seguida, atualiza `rNextPosition` para referir-se para o próximo elemento no mapa.  
  
```  
void GetNextAssoc(
    POSITION& rPosition,
    KEY& rKey,
    VALUE& rValue) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPosition`  
 Especifica uma referência a um **posição** valor retornado por uma anterior `GetNextAssoc` ou `BASE_CLASS` **:: GetStartPosition** chamar.  
  
 *CHAVE*  
 Parâmetro de modelo especificando o tipo de chaves do mapa.  
  
 `rKey`  
 Especifica a chave retornada do elemento recuperado.  
  
 *VALOR*  
 Parâmetro de modelo especificando o tipo de valores do mapa.  
  
 `rValue`  
 Especifica o valor retornado do elemento recuperado.  
  
### <a name="remarks"></a>Comentários  
 Essa função é mais útil para iterar todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.  
  
 Se o elemento recuperado é o último no mapa, em seguida, o novo valor de `rNextPosition` é definido como **nulo**.  
  
 Essa função embutida chama `BASE_CLASS` **:: GetNextAssoc**.  
  
##  <a name="lookup"></a>CTypedPtrMap::Lookup  
 `Lookup`usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que corresponda exatamente.  
  
```  
BOOL Lookup(BASE_CLASS ::BASE_ARG_KEY key, VALUE& rValue) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `BASE_CLASS`  
 Parâmetro de modelo especificando a classe base da classe deste mapa.  
  
 `key`  
 A chave do elemento a ser pesquisado.  
  
 *VALOR*  
 Parâmetro de modelo especificando o tipo de valores armazenados neste mapa.  
  
 `rValue`  
 Especifica o valor retornado do elemento recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o elemento foi encontrado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função embutida chama `BASE_CLASS` **:: pesquisa**.  
  
##  <a name="operator_at"></a>[CTypedPtrMap::operator]  
 Este operador pode ser usado apenas no lado esquerdo de uma instrução de atribuição (um l-value).  
  
```  
VALUE& operator[ ](base_class ::base_arg_key key);
```  
  
### <a name="parameters"></a>Parâmetros  
 *VALOR*  
 Parâmetro de modelo especificando o tipo de valores armazenados neste mapa.  
  
 `BASE_CLASS`  
 Parâmetro de modelo especificando a classe base da classe deste mapa.  
  
 `key`  
 A chave do elemento a ser pesquisado ou criado no mapa.  
  
### <a name="remarks"></a>Comentários  
 Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado. Não há nenhum "direita" (r-Value) equivalente ao operador porque há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para a recuperação do elemento.  
  
##  <a name="removekey"></a>CTypedPtrMap::RemoveKey  
 Chama essa função de membro `BASE_CLASS` **:: RemoveKey**.  
  
```  
BOOL RemoveKey(KEY key);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CHAVE*  
 Parâmetro de modelo especificando o tipo de chaves do mapa.  
  
 `key`  
 Chave do elemento a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a entrada foi encontrada e removida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey).  
  
##  <a name="setat"></a>CTypedPtrMap::SetAt  
 Chama essa função de membro `BASE_CLASS` **:: SetAt**.  
  
```  
void SetAt(KEY key, VALUE newValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CHAVE*  
 Parâmetro de modelo especificando o tipo de chaves do mapa.  
  
 `key`  
 Especifica o valor da chave do newValue.  
  
 `newValue`  
 Especifica o ponteiro de objeto que é o valor do novo elemento.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais comentários, consulte [CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)   
 [Classe de CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)   
 [Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)   
 [Classe de CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)

