---
title: Classe CAtlArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlArray
- ATLCOLL/ATL::CAtlArray
- ATLCOLL/ATL::Add
- ATLCOLL/ATL::Append
- ATLCOLL/ATL::AssertValid
- ATLCOLL/ATL::CAtlArray
- ATLCOLL/ATL::Copy
- ATLCOLL/ATL::FreeExtra
- ATLCOLL/ATL::GetAt
- ATLCOLL/ATL::GetCount
- ATLCOLL/ATL::GetData
- ATLCOLL/ATL::InsertArrayAt
- ATLCOLL/ATL::InsertAt
- ATLCOLL/ATL::IsEmpty
- ATLCOLL/ATL::RemoveAll
- ATLCOLL/ATL::RemoveAt
- ATLCOLL/ATL::SetAt
- ATLCOLL/ATL::SetAtGrow
- ATLCOLL/ATL::SetCount
- ATLCOLL/ATL::INARGTYPE
- ATLCOLL/ATL::OUTARGTYPE
dev_langs:
- C++
helpviewer_keywords:
- CAtlArray class
ms.assetid: 0b503aa8-2357-40af-a326-6654bf1da098
caps.latest.revision: 21
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
translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: c81ee3121ffbb9d89374afd4e09a3a6044c4b70b
ms.lasthandoff: 03/31/2017

---
# <a name="catlarray-class"></a>Classe CAtlArray
Essa classe implementa um objeto de matriz.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename E, class ETraits = CElementTraits<E>>
class CAtlArray
```  
  
#### <a name="parameters"></a>Parâmetros  
 *E*  
 O tipo de dados a serem armazenados na matriz.  
  
 *ETraits*  
 O código usado para copiar ou mover elementos.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Adicionar](#add)|Chame esse método para adicionar um elemento para o objeto de matriz.|  
|[Acrescentar](#append)|Chame esse método para adicionar o conteúdo de uma matriz ao final do outro.|  
|[AssertValid](#assertvalid)|Chame este método para confirmar se o objeto de matriz é válido.|  
|[CAtlArray](#catlarray)|O construtor.|  
|[~ CAtlArray](#dtor)|O destruidor.|  
|[Copiar](#copy)|Chame este método para copiar os elementos de uma matriz para outro.|  
|[FreeExtra](#freeextra)|Chame esse método para remover quaisquer elementos vazios da matriz.|  
|[GetAt](#getat)|Chame este método para recuperar um único elemento do objeto de matriz.|  
|[GetCount](#getcount)|Chame este método para retornar o número de elementos armazenados na matriz.|  
|[GetData](#getdata)|Chame este método para retornar um ponteiro para o primeiro elemento na matriz.|  
|[InsertArrayAt](#insertarrayat)|Chame esse método para inserir uma matriz a outra.|  
|[InsertAt](#insertat)|Chame este método para inserir um novo elemento (ou várias cópias de um elemento) em um objeto de matriz.|  
|[IsEmpty](#isempty)|Chame este método para testar se a matriz está vazia.|  
|[RemoveAll](#removeall)|Chame esse método para remover todos os elementos do objeto de matriz.|  
|[RemoveAt](#removeat)|Chame esse método para remover um ou mais elementos da matriz.|  
|[SetAt](#setat)|Chame esse método para definir o valor de um elemento no objeto de matriz.|  
|[SetAtGrow](#setatgrow)|Chame este método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.|  
|[SetCount](#setcount)|Chame este método para definir o tamanho do objeto de matriz.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador&#91;&#93;](#operator_at)|Chame este operador para retornar uma referência a um elemento na matriz.|  

  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[INARGTYPE](#inargtype)|O tipo de dados a ser usado para a adição de elementos na matriz.|  
|[OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos da matriz.|  
  
## <a name="remarks"></a>Comentários  
 **CAtlArray** fornece métodos para criar e gerenciar uma matriz de elementos de um tipo definido pelo usuário. Embora semelhante às matrizes de C padrão, o **CAtlArray** objeto dinamicamente pode reduzir e cresça conforme necessário. O índice de matriz sempre começa na posição 0 e o limite superior pode ser corrigido ou permitido para expandir conforme novos elementos são adicionados.  
  
 Para matrizes com um pequeno número de elementos, a classe ATL [CSimpleArray](../../atl/reference/csimplearray-class.md) pode ser usado.  
  
 **CAtlArray** está intimamente relacionado do MFC **CArray** classe e funcionará em um projeto MFC, embora sem suporte de serialização.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="add"></a>CAtlArray::Add  
 Chame esse método para adicionar um elemento para o objeto de matriz.  
  
```
size_t Add(INARGTYPE element);
size_t Add();
```  
  
### <a name="parameters"></a>Parâmetros  
 `element`  
 O elemento a ser adicionada à matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice do elemento adicionado.  
  
### <a name="remarks"></a>Comentários  
 O elemento novo é adicionado ao final da matriz. Se nenhum elemento for fornecido, um elemento vazio é adicionado; ou seja, a matriz aumenta de tamanho como se um elemento real foi adicionado. Se a operação falhar, [AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow) é chamado com o argumento E_OUTOFMEMORY.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 1](../../atl/codesnippet/cpp/catlarray-class_1.cpp)]  
  
##  <a name="append"></a>CAtlArray::Append  
 Chame esse método para adicionar o conteúdo de uma matriz ao final do outro.  
  
```
size_t Append(const CAtlArray<E, ETraits>& aSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `aSrc`  
 A matriz para anexar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice do primeiro elemento anexado.  
  
### <a name="remarks"></a>Comentários  
 Os elementos na matriz fornecida são adicionados ao final da matriz existente. Se necessário, será possível alocar memória para acomodar os novos elementos.  
  
 As matrizes devem ser do mesmo tipo e não é possível acrescentar uma matriz a mesmo.  
  
 Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` argumento não é uma matriz válida ou se `aSrc` refere-se ao mesmo objeto. Nas compilações de lançamento, argumentos inválidos podem resultar em comportamento imprevisível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 2](../../atl/codesnippet/cpp/catlarray-class_2.cpp)]  
  
##  <a name="assertvalid"></a>CAtlArray::AssertValid  
 Chame este método para confirmar se o objeto de matriz é válido.  
  
```
void AssertValid() const;
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de matriz não é válido, `ATLASSERT` lançará uma asserção. Este método está disponível somente se Debug está definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 3](../../atl/codesnippet/cpp/catlarray-class_3.cpp)]  
  
##  <a name="catlarray"></a>CAtlArray::CAtlArray  
 O construtor.  
  
```
CAtlArray() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o objeto de matriz.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 4](../../atl/codesnippet/cpp/catlarray-class_4.cpp)]  
  
##  <a name="dtor"></a>CAtlArray:: ~ CAtlArray  
 O destruidor.  
  
```
~CAtlArray() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos usados pelo objeto de matriz.  
  
##  <a name="copy"></a>CAtlArray::Copy  
 Chame este método para copiar os elementos de uma matriz para outro.  
  
```
void Copy(const CAtlArray<E, ETraits>& aSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `aSrc`  
 A origem dos elementos a serem copiados para uma matriz.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para substituir os elementos de uma matriz com os elementos da matriz de outro. Se necessário, será possível alocar memória para acomodar os novos elementos. Não é possível copiar os elementos de uma matriz a mesmo.  
  
 Se o conteúdo existente da matriz devem ser mantidos, use [CAtlArray::Append](#append) em vez disso.  
  
 Em compilações de depuração, será gerado um ATLASSERT se existente `CAtlArray` objeto não é válido, ou se `aSrc` refere-se ao mesmo objeto. Nas compilações de lançamento, argumentos inválidos podem resultar em comportamento imprevisível.  
  
> [!NOTE]
> `CAtlArray::Copy`não oferece suporte a matrizes que consiste em elementos criados com o [CAutoPtr](../../atl/reference/cautoptr-class.md) classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 5](../../atl/codesnippet/cpp/catlarray-class_5.cpp)]  
  
##  <a name="freeextra"></a>CAtlArray::FreeExtra  
 Chame esse método para remover quaisquer elementos vazios da matriz.  
  
```
void FreeExtra() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Todos os elementos vazios são removidos, mas o tamanho e o limite superior da matriz permanecem inalterados.  
  
 Um ATLASSERT em compilações de depuração, será gerado se o objeto CAtlArray não é válido ou se a matriz excede o tamanho máximo.  
  
##  <a name="getat"></a>CAtlArray::GetAt  
 Chame que esse método recupera um único elemento do objeto de matriz.  
  
```
const E& GetAt(size_t iElement) const throw();
E& GetAt(size_t iElement) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O valor de índice do elemento da matriz para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao elemento de matriz necessária.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, será gerado um ATLASSERT se `iElement` excede o número de elementos na matriz. Nas compilações de lançamento, um argumento inválido pode resultar em comportamento imprevisível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities 6](../../atl/codesnippet/cpp/catlarray-class_6.cpp)]  
  
##  <a name="getcount"></a>CAtlArray::GetCount  
 Chame este método para retornar o número de elementos armazenados na matriz.  
  
```
size_t GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos armazenados na matriz.  
  
### <a name="remarks"></a>Comentários  
 Como o primeiro elemento na matriz na posição 0, o valor retornado por `GetCount` é sempre 1 maior que o maior índice.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlArray::GetAt](#getat).  
  
##  <a name="getdata"></a>CAtlArray::GetData  
 Chame este método para retornar um ponteiro para o primeiro elemento na matriz.  
  
```
E* GetData() throw();
const E* GetData() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o local de memória, armazenando o primeiro elemento na matriz. Se nenhum elemento estiver disponível, NULL será retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #7](../../atl/codesnippet/cpp/catlarray-class_7.cpp)]  
  
##  <a name="inargtype"></a>CAtlArray::INARGTYPE  
 O tipo de dados a ser usado para a adição de elementos na matriz.  
  
```
typedef ETraits::INARGTYPE INARGTYPE;
```  
  
##  <a name="insertarrayat"></a>CAtlArray::InsertArrayAt  
 Chame esse método para inserir uma matriz a outra.  
  
```
void InsertArrayAt(size_t iStart, const CAtlArray<E, ETraits>* paNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iStart`  
 O índice no qual a matriz é a ser inserido.  
  
 `paNew`  
 A matriz a ser inserido.  
  
### <a name="remarks"></a>Comentários  
 Elementos da matriz `paNew` são copiados para o objeto de matriz, começando no elemento `iStart`. Os elementos da matriz existente serão movidos para evitar que está sendo substituído.  
  
 Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não é válido, ou se o `paNew` ponteiro é nulo ou inválido.  
  
> [!NOTE]
> `CAtlArray::InsertArrayAt`não oferece suporte a matrizes que consiste em elementos criados com o [CAutoPtr](../../atl/reference/cautoptr-class.md) classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 8](../../atl/codesnippet/cpp/catlarray-class_8.cpp)]  
  
##  <a name="insertat"></a>CAtlArray::InsertAt  
 Chame este método para inserir um novo elemento (ou várias cópias de um elemento) em um objeto de matriz.  
  
```
void InsertAt(size_t iElement, INARGTYPE element, size_t nCount = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O índice onde o elemento ou elementos serão inseridos.  
  
 `element`  
 O valor do elemento ou elementos a serem inseridos.  
  
 `nCount`  
 O número de elementos a serem adicionados.  
  
### <a name="remarks"></a>Comentários  
 Insere um ou mais elementos na matriz, começando no índice `iElement`. Elementos existentes são movidos para evitar que está sendo substituído.  
  
 Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` o objeto é inválido, o número de elementos a serem adicionados é zero ou o número combinado dos elementos é muito grande para a matriz para conter. Em compilações para venda, passar parâmetros inválidos pode causar resultados imprevisíveis.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 9](../../atl/codesnippet/cpp/catlarray-class_9.cpp)]  
  
##  <a name="isempty"></a>CAtlArray::IsEmpty  
 Chame este método para testar se a matriz está vazia.  
  
```
bool IsEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a matriz estiver vazia, caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 A matriz deve ser vazio se não contém nenhum elemento. Portanto, mesmo se a matriz contém elementos vazios, não está vazio.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #10](../../atl/codesnippet/cpp/catlarray-class_10.cpp)]  
  
##  <a name="operator_at"></a>[CAtlArray::operator]  
 Chame este operador para retornar uma referência a um elemento na matriz.  
  
```
E& operator[](size_t ielement) throw();
const E& operator[](size_t ielement) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O valor de índice do elemento da matriz para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao elemento de matriz necessária.  
  
### <a name="remarks"></a>Comentários  
 Executa uma função semelhante para [CAtlArray::GetAt](#getat). Ao contrário da classe do MFC [CArray](../../mfc/reference/carray-class.md), esse operador não pode ser usado como um substituto para [CAtlArray::SetAt](#setat).  
  
 Em compilações de depuração, será gerado um ATLASSERT se `iElement` excede o número total de elementos na matriz. Em compilações para venda, um parâmetro inválido pode causar resultados imprevisíveis.  
  
##  <a name="outargtype"></a>CAtlArray::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos da matriz.  
  
```
typedef ETraits::OUTARGTYPE OUTARGTYPE;
```  
  
##  <a name="removeall"></a>CAtlArray::RemoveAll  
 Chame esse método para remover todos os elementos do objeto de matriz.  
  
```
void RemoveAll() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todos os elementos do objeto de matriz.  
  
 Este método chama [CAtlArray::SetCount](#setcount) para redimensionar a matriz e libera subsequentemente qualquer memória alocada.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlArray::IsEmpty](#isempty).  
  
##  <a name="removeat"></a>CAtlArray::RemoveAt  
 Chame esse método para remover um ou mais elementos da matriz.  
  
```
void RemoveAt(size_t iElement, size_t nCount = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O índice do primeiro elemento a ser removido.  
  
 `nCount`  
 O número de elementos a serem removidos.  
  
### <a name="remarks"></a>Comentários  
 Remove um ou mais elementos da matriz. Todos os elementos restantes são deslocados para baixo. O limite superior é reduzido, mas a memória não é liberada até que uma chamada para [CAtlArray::FreeExtra](#freeextra) é feita.  
  
 Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não é válido, ou se o total combinado de `iElement` e `nCount` excede o número total de elementos na matriz. Em compilações para venda, parâmetros inválidos podem causar resultados imprevisíveis.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities n º 11](../../atl/codesnippet/cpp/catlarray-class_11.cpp)]  
  
##  <a name="setat"></a>CAtlArray::SetAt  
 Chame esse método para definir o valor de um elemento no objeto de matriz.  
  
```
void SetAt(size_t iElement, INARGTYPE element);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O índice que aponta para o elemento de matriz para definir.  
  
 `element`  
 O novo valor do elemento especificado.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, será gerado um ATLASSERT se `iElement` excede o número de elementos na matriz. Em compilações para venda, um parâmetro inválido pode causar resultados imprevisíveis.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlArray::GetAt](#getat).  
  
##  <a name="setcount"></a>CAtlArray::SetCount  
 Chame este método para definir o tamanho do objeto de matriz.  
  
```
bool SetCount(size_t nNewSize, int nGrowBy = - 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewSize`  
 O tamanho necessário da matriz.  
  
 `nGrowBy`  
 Um valor usado para determinar quão grande para tornar o buffer. Um valor -1 faz com que um valor calculado internamente a ser usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a matriz é redimensionado com êxito, false caso contrário.  
  
### <a name="remarks"></a>Comentários  
 A matriz pode ser aumentada ou reduzida em tamanho. Se aumentado, elementos vazios adicional são adicionados à matriz. Se diminuir, os elementos com o maior índice serão excluídos e memória liberada.  
  
 Use esse método para definir o tamanho da matriz antes de usá-lo. Se `SetCount` não for usado, o processo de adição de elementos, e a alocação de memória subsequentes executadas — reduzirá o desempenho e memória de fragmento.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CAtlArray::GetData](#getdata).  
  
##  <a name="setatgrow"></a>CAtlArray::SetAtGrow  
 Chame este método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.  
  
```
void SetAtGrow(size_t iElement, INARGTYPE element);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iElement`  
 O índice que aponta para o elemento de matriz para definir.  
  
 `element`  
 O novo valor do elemento especificado.  
  
### <a name="remarks"></a>Comentários  
 Substitui o valor do elemento apontado pelo índice. Se `iElement` é maior do que o tamanho atual da matriz, a matriz será aumentada automaticamente usando uma chamada para [CAtlArray::SetCount](#setcount). Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não é válido. Em compilações para venda, parâmetros inválidos podem causar resultados imprevisíveis.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities #12](../../atl/codesnippet/cpp/catlarray-class_12.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de MMXSwarm](../../visual-cpp-samples.md)   
 [Exemplo de DynamicConsumer](../../visual-cpp-samples.md)   
 [Exemplo de UpdatePV](../../visual-cpp-samples.md)   
 [Exemplo de marca de seleção](../../visual-cpp-samples.md)   
 [Classe CArray](../../mfc/reference/carray-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

