---
title: Classe CArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CArray
- AFXTEMPL/CArray
- AFXTEMPL/CArray::CArray
- AFXTEMPL/CArray::Add
- AFXTEMPL/CArray::Append
- AFXTEMPL/CArray::Copy
- AFXTEMPL/CArray::ElementAt
- AFXTEMPL/CArray::FreeExtra
- AFXTEMPL/CArray::GetAt
- AFXTEMPL/CArray::GetCount
- AFXTEMPL/CArray::GetData
- AFXTEMPL/CArray::GetSize
- AFXTEMPL/CArray::GetUpperBound
- AFXTEMPL/CArray::InsertAt
- AFXTEMPL/CArray::IsEmpty
- AFXTEMPL/CArray::RemoveAll
- AFXTEMPL/CArray::RemoveAt
- AFXTEMPL/CArray::SetAt
- AFXTEMPL/CArray::SetAtGrow
- AFXTEMPL/CArray::SetSize
dev_langs:
- C++
helpviewer_keywords:
- CArray class
- arrays [C++], classes
- templates, collection classes
- collection classes, template-based
ms.assetid: fead8b00-4cfd-4625-ad0e-251df62ba92f
caps.latest.revision: 33
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: d76790072babb607c223937d9c9dae67f90d50b5
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="carray-class"></a>Classe CArray
Oferece suporte a matrizes que são como matrizes de C, mas podem reduzir e dinamicamente cresça conforme necessário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class TYPE, class ARG_TYPE = const TYPE&>  
class CArray : public CObject  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TYPE`  
 Parâmetro de modelo que especifica o tipo de objetos armazenados na matriz. `TYPE`é um parâmetro que é retornado por `CArray`.  
  
 `ARG` *_* `TYPE`  
 Parâmetro de modelo que especifica o tipo de argumento que é usado para acessar objetos armazenados na matriz. Geralmente, uma referência a `TYPE`. `ARG_TYPE`é um parâmetro que é passado para `CArray`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CArray::CArray](#carray)|Constrói uma matriz vazia.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CArray::Add](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|  
|[CArray::Append](#append)|Acrescenta outra matriz para a matriz; aumenta a matriz se necessário|  
|[CArray::Copy](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|  
|[CArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|  
|[CArray::GetAt](#getat)|Retorna o valor a um determinado índice.|  
|[CArray::GetCount](#getcount)|Obtém o número de elementos nesta matriz.|  
|[CArray::GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser **nulo**.|  
|[CArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|  
|[CArray::GetUpperBound](#getupperbound)|Retorna o maior índice válido.|  
|[CArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|  
|[CArray::IsEmpty](#isempty)|Determina se a matriz está vazia.|  
|[CArray::RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|  
|[CArray::RemoveAt](#removeat)|Remove um elemento a um índice específico.|  
|[CArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|  
|[CArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|  
|[CArray::SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|  
  
### <a name="public-operators"></a>Operadores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator&#91;&#93;](#operator_at)|Define ou obtém o elemento no índice especificado.|  
  
## <a name="remarks"></a>Comentários  
 Índices de matriz sempre começam na posição 0. Você pode decidir se deseja corrigir o limite superior ou ativar a matriz expandir quando você adiciona elementos anteriores atual associado. Memória está alocada continuamente o limite superior, mesmo que alguns elementos são nulos.  
  
> [!NOTE]
>  A maioria dos métodos redimensionar uma `CArray` de objeto ou adicionar elementos a ela usam [memcpy_s](../../c-runtime-library/reference/memcpy-s-wmemcpy-s.md) para mover os elementos. Este é um problema porque `memcpy_s` não é compatível com todos os objetos que exigem o construtor seja chamado. Se os itens a `CArray` não são compatíveis com `memcpy_s`, você deve criar um novo `CArray` de tamanho apropriado. Em seguida, você deve usar [CArray::Copy](#copy) e [CArray::SetAt](#setat) para preencher a nova matriz porque esses métodos usam um operador de atribuição em vez de `memcpy_s`.  
  
 Assim como acontece com uma matriz de C, o tempo de acesso para um `CArray` elemento indexado é constante e é independente do tamanho da matriz.  
  
> [!TIP]
>  Antes de usar uma matriz, use [SetSize](#setsize) para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 Se você precisar de um despejo de elementos individuais em uma matriz, você deve definir a profundidade do [CDumpContext](../../mfc/reference/cdumpcontext-class.md) objeto como 1 ou maior.  
  
 Determinadas funções de membro dessa chamada de classe auxiliar global funções que devem ser personalizadas para a maioria dos usos do `CArray` classe. Consulte o tópico [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção de Macros e globais MFC.  
  
 Derivação de classe de matriz é semelhante a derivação de lista.  
  
 Para obter mais informações sobre como usar `CArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CArray`  
  
## <a name="requirements"></a>Requisitos  
 `Header:`afxtempl.h  
  
##  <a name="add"></a>CArray::Add  
 Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.  
  
```  
INT_PTR Add(ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ARG_TYPE`  
 Especifica o tipo de referência de elementos nesta matriz de argumentos de parâmetro de modelo.  
  
 `newElement`  
 O elemento a ser adicionado a essa matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do elemento adicionado.  
  
### <a name="remarks"></a>Comentários  
 Se [SetSize](#setsize) foi usado com um `nGrowBy` valor maior que 1, em seguida, memória adicional pode ser alocado. No entanto, o limite superior aumentam em 1 somente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #22](../../mfc/codesnippet/cpp/carray-class_1.cpp)]  
  
##  <a name="append"></a>CArray::Append  
 Chame essa função de membro para adicionar o conteúdo de uma matriz ao final do outro.  
  
```  
INT_PTR Append(const CArray& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 Fonte dos elementos a serem acrescentados a uma matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro elemento anexado.  
  
### <a name="remarks"></a>Comentários  
 As matrizes devem ser do mesmo tipo.  
  
 Se necessário, **Append** pode alocar memória adicional para acomodar os elementos anexados à matriz.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #23](../../mfc/codesnippet/cpp/carray-class_2.cpp)]  
  
##  <a name="carray"></a>CArray::CArray  
 Constrói uma matriz vazia.  
  
```  
CArray();
```  
  
### <a name="remarks"></a>Comentários  
 A matriz aumenta um elemento por vez.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #24](../../mfc/codesnippet/cpp/carray-class_3.cpp)]  
  
##  <a name="copy"></a>CArray::Copy  
 Use esta função de membro para copiar os elementos de uma matriz para outra.  
  
```  
void Copy(const CArray& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 Fonte dos elementos a serem copiados para uma matriz.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para substituir os elementos de uma matriz com os elementos da matriz de outro.  
  
 **Cópia** não libera memória; no entanto, se necessário, **cópia** pode alocar memória adicional para acomodar os elementos copiados para a matriz.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCCollections](../../mfc/codesnippet/cpp/carray-class_4.cpp)]  
  
##  <a name="elementat"></a>CArray::ElementAt  
 Retorna uma referência temporária para o elemento especificado dentro da matriz.  
  
```  
TYPE& ElementAt(INT_PTR nIndex);  
const TYPE& ElementAt(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um elemento de matriz.  
  
### <a name="remarks"></a>Comentários  
 Ele é usado para implementar o operador de atribuição da esquerda para matrizes.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [GetSize](#getsize).  
  
##  <a name="freeextra"></a>CArray::FreeExtra  
 Libera qualquer memória extra que foi alocada enquanto a matriz foi aumentada.  
  
```  
void FreeExtra();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função não tem efeito sobre o tamanho ou o limite superior da matriz.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [GetData](#getdata).  
  
##  <a name="getat"></a>CArray::GetAt  
 Retorna o elemento de matriz no índice especificado.  
  
```  
TYPE& GetAt(INT_PTR nIndex);  
const TYPE& GetAt(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo dos elementos da matriz de parâmetro de modelo.  
  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de matriz no momento nesse índice.  
  
### <a name="remarks"></a>Comentários  
 Passando um valor negativo ou um valor maior que o valor retornado por `GetUpperBound` resultará em uma declaração com falha.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[26 de # NVC_MFCCollections](../../mfc/codesnippet/cpp/carray-class_5.cpp)]  
  
##  <a name="getcount"></a>CArray::GetCount  
 Retorna o número de elementos da matriz.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na matriz.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de elementos na matriz. Como os índices com base em zero, o tamanho é maior que o maior índice de 1. Chamar esse método gerará o mesmo resultado que o [CArray::GetSize](#getsize) método.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #27](../../mfc/codesnippet/cpp/carray-class_6.cpp)]  
  
##  <a name="getdata"></a>CArray::GetData  
 Use esta função de membro para obter acesso direto aos elementos em uma matriz.  
  
```  
const TYPE* GetData() const; 
TYPE* GetData();
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Especifica o tipo dos elementos da matriz de parâmetro de modelo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento de matriz.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum elemento estiver disponível, `GetData` retorna um valor nulo.  
  
 Enquanto o acesso direto aos elementos de uma matriz pode ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao chamar `GetData`; os erros que você fizer diretamente afetam os elementos da sua matriz.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections n º 28](../../mfc/codesnippet/cpp/carray-class_7.cpp)]  
  
##  <a name="getsize"></a>CArray::GetSize  
 Retorna o tamanho da matriz.  
  
```  
INT_PTR GetSize() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Como os índices com base em zero, o tamanho é maior que o maior índice de 1. Chamar esse método gerará o mesmo resultado que o [CArray::GetCount](#getcount) método.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFCCollections](../../mfc/codesnippet/cpp/carray-class_8.cpp)]  
  
##  <a name="getupperbound"></a>CArray::GetUpperBound  
 Retorna o limite superior atual dessa matriz.  
  
```  
INT_PTR GetUpperBound() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Como os índices de matriz são baseadas em zero, essa função retorna um valor de 1 menor `GetSize`.  
  
 A condição **(GetUpperBound)** = -1 indica que a matriz não contém elementos.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArray::GetAt](#getat).  
  
##  <a name="insertat"></a>CArray::InsertAt  
 A primeira versão do `InsertAt` insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz.  
  
```  
void InsertAt(
    INT_PTR nIndex,
    ARG_TYPE newElement,  
    INT_PTR nCount = 1);
 
void InsertAt(
    INT_PTR nStartIndex,  
    CArray* pNewArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por `GetUpperBound`.  
  
 `ARG_TYPE`  
 Parâmetro de modelo especificando o tipo dos elementos nesta matriz.  
  
 `newElement`  
 O elemento a ser colocado nesta matriz.  
  
 `nCount`  
 O número de vezes que esse elemento deve ser inserido (o padrão é 1).  
  
 `nStartIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por [GetUpperBound](#getupperbound).  
  
 `pNewArray`  
 Outra matriz que contém os elementos a serem adicionados a essa matriz.  
  
### <a name="remarks"></a>Comentários  
 No processo, desloca para cima (aumentando o índice) do elemento existente nesse índice e desloca a todos os elementos acima dele.  
  
 A segunda versão insere todos os elementos de outro `CArray` coleção, a partir de `nStartIndex` posição.  
  
 O `SetAt` função, por outro lado, substitui um elemento da matriz especificada e não deslocar a todos os elementos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCCollections](../../mfc/codesnippet/cpp/carray-class_9.cpp)]  
  
##  <a name="isempty"></a>CArray::IsEmpty  
 Determina se a matriz está vazia.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a matriz não contém elementos; Caso contrário, 0.  
  
##  <a name="operator_at"></a>CArray::operator\[\]  
 Esses operadores subscript são um substituto conveniente para o [SetAt](#setat) e [GetAt](#getat) funções.  
  
```  
TYPE& operator[](int_ptr nindex);  
const TYPE& operator[](int_ptr nindex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TIPO DE*  
 Parâmetro de modelo especificando o tipo dos elementos nesta matriz.  
  
 `nIndex`  
 Índice do elemento a ser acessado.  
  
### <a name="remarks"></a>Comentários  
 O operador primeiro, chamado de matrizes que não são **const**, pode ser usado em à direita (r) ou à esquerda (l-value) de uma instrução de atribuição. A segunda chamada para **const** matrizes, pode ser usado somente no lado direito.  
  
 A versão de depuração da biblioteca declara se subscrito (tanto no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #34](../../mfc/codesnippet/cpp/carray-class_10.cpp)]  
  
##  <a name="relocateelements"></a>CArray::RelocateElements  
 Realoca dados para um novo buffer quando a matriz deve aumentam ou diminuem.  
  
```  
template<class TYPE, class ARG_TYPE>  
AFX_INLINE void CArray<TYPE, ARG_TYPE>::RelocateElements(
    TYPE* pNewData,  
    const TYPE* pData,  
    INT_PTR nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pNewData`  
 Um novo buffer para a matriz de elementos.  
  
 `pData`  
 A matriz antiga de elementos.  
  
 `nCount`  
 Número de elementos na matriz antigo.  
  
### <a name="remarks"></a>Comentários  
 `pNewData`sempre é grande o suficiente para manter todos os `pData` elementos.  
  
 O [CArray](../../mfc/reference/carray-class.md) implementação usa esse método para copiar os dados antigos para um novo buffer quando a matriz deve ser ampliada ou reduzida (quando [SetSize](#setsize) ou [FreeExtra](#freeextra) são chamados). A implementação padrão apenas copia os dados.  
  
 Para matrizes em que um elemento contém um ponteiro para um de seus próprios membros ou outra estrutura contém um ponteiro para um dos elementos da matriz, os ponteiros não são atualizados na cópia simples. Nesse caso, você pode corrigir ponteiros implementando uma especialização de `RelocateElements` com os tipos de relevantes. Você também é responsável por cópia de dados.  
  
##  <a name="removeall"></a>CArray::RemoveAll  
 Remove todos os elementos dessa matriz.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Se a matriz estiver vazia, a função ainda funciona.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #31](../../mfc/codesnippet/cpp/carray-class_11.cpp)]  
  
##  <a name="removeat"></a>CArray::RemoveAt  
 Remove um ou mais elementos, começando em um índice especificado em uma matriz.  
  
```  
void RemoveAt(
    INT_PTR nIndex,  
    INT_PTR nCount = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).  
  
 `nCount`  
 O número de elementos a serem removidos.  
  
### <a name="remarks"></a>Comentários  
 O processo, ele muda para baixo de todos os elementos acima do elemento removido (s). Ele diminui a superior associado da matriz, mas não libera memória.  
  
 Se você tentar remover mais elementos que estão contidos na matriz acima do ponto de remoção, declara a versão de depuração da biblioteca.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections #32](../../mfc/codesnippet/cpp/carray-class_12.cpp)]  
  
##  <a name="setat"></a>CArray::SetAt  
 Define o elemento de matriz no índice especificado.  
  
```  
void SetAt(INT_PTR nIndex, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por [GetUpperBound](#getupperbound).  
  
 `ARG_TYPE`  
 Especifica o tipo de argumentos usados para fazer referência a elementos da matriz de parâmetro de modelo.  
  
 `newElement`  
 O novo valor do elemento a ser armazenado na posição especificada.  
  
### <a name="remarks"></a>Comentários  
 `SetAt`não fará com que a matriz de crescimento. Use [SetAtGrow](#setatgrow) se você quiser que a matriz para crescer automaticamente.  
  
 Certifique-se de que o valor de índice representa uma posição válida na matriz. Se ele está fora dos limites, declara a versão de depuração da biblioteca.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [GetAt](#getat).  
  
##  <a name="setatgrow"></a>CArray::SetAtGrow  
 Define o elemento de matriz no índice especificado.  
  
```  
void SetAtGrow(INT_PTR nIndex, ARG_TYPE newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0.  
  
 `ARG_TYPE`  
 Especifica o tipo de elementos na matriz de parâmetro de modelo.  
  
 `newElement`  
 O elemento a ser adicionado a essa matriz. Um **nulo** valor permitido.  
  
### <a name="remarks"></a>Comentários  
 A matriz cresce automaticamente se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFCCollections](../../mfc/codesnippet/cpp/carray-class_13.cpp)]  
  
##  <a name="setsize"></a>CArray::SetSize  
 Estabelece o tamanho de uma matriz vazia ou existente; aloca memória se necessário.  
  
```  
void SetSize(
    INT_PTR nNewSize,  
    INT_PTR nGrowBy = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewSize`  
 O tamanho da matriz novo (número de elementos). Deve ser maior ou igual a 0.  
  
 `nGrowBy`  
 O número mínimo de slots de elemento para alocar se um aumento de tamanho é necessário.  
  
### <a name="remarks"></a>Comentários  
 Se o novo tamanho for menor que o tamanho anterior, em seguida, a matriz será truncada e não utilizada toda a memória é liberada.  
  
 Use esta função para definir o tamanho da sua matriz antes de começar a usar a matriz. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 O `nGrowBy` parâmetro afeta a alocação de memória interna enquanto a matriz está aumentando. Seu uso não afeta o tamanho da matriz conforme relatado pelo [GetSize](#getsize) e [GetUpperBound](#getupperbound). Se o valor padrão é usado, o MFC aloca memória de forma calculada para evitar a fragmentação de memória e otimizar a eficiência na maioria dos casos.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [GetData](#getdata).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObArray](../../mfc/reference/cobarray-class.md)   
 [Auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md)

