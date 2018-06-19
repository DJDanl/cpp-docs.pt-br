---
title: Classe CObArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CObArray
- AFXCOLL/CObArray
- AFXCOLL/CObArray::CObArray
- AFXCOLL/CObArray::Add
- AFXCOLL/CObArray::Append
- AFXCOLL/CObArray::Copy
- AFXCOLL/CObArray::ElementAt
- AFXCOLL/CObArray::FreeExtra
- AFXCOLL/CObArray::GetAt
- AFXCOLL/CObArray::GetCount
- AFXCOLL/CObArray::GetData
- AFXCOLL/CObArray::GetSize
- AFXCOLL/CObArray::GetUpperBound
- AFXCOLL/CObArray::InsertAt
- AFXCOLL/CObArray::IsEmpty
- AFXCOLL/CObArray::RemoveAll
- AFXCOLL/CObArray::RemoveAt
- AFXCOLL/CObArray::SetAt
- AFXCOLL/CObArray::SetAtGrow
- AFXCOLL/CObArray::SetSize
dev_langs:
- C++
helpviewer_keywords:
- CObArray [MFC], CObArray
- CObArray [MFC], Add
- CObArray [MFC], Append
- CObArray [MFC], Copy
- CObArray [MFC], ElementAt
- CObArray [MFC], FreeExtra
- CObArray [MFC], GetAt
- CObArray [MFC], GetCount
- CObArray [MFC], GetData
- CObArray [MFC], GetSize
- CObArray [MFC], GetUpperBound
- CObArray [MFC], InsertAt
- CObArray [MFC], IsEmpty
- CObArray [MFC], RemoveAll
- CObArray [MFC], RemoveAt
- CObArray [MFC], SetAt
- CObArray [MFC], SetAtGrow
- CObArray [MFC], SetSize
ms.assetid: 27894efd-2370-4776-9ed9-24a98492af17
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3995734918f50ed01fe6df7fb034c3ea37b630cd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377908"
---
# <a name="cobarray-class"></a>Classe CObArray
Oferece suporte a matrizes de `CObject` ponteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CObArray : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObArray::CObArray](#cobarray)|Constrói uma matriz vazia para `CObject` ponteiros.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObArray::Add](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|  
|[CObArray::Append](#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::Copy](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|  
|[CObArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|  
|[CObArray::GetAt](#getat)|Retorna o valor a um determinado índice.|  
|[CObArray::GetCount](#getcount)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser **nulo**.|  
|[CObArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetUpperBound](#getupperbound)|Retorna o maior índice válido.|  
|[CObArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|  
|[CObArray::IsEmpty](#isempty)|Determina se a matriz está vazia.|  
|[CObArray::RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|  
|[CObArray::RemoveAt](#removeat)|Remove um elemento a um índice específico.|  
|[CObArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|  
|[CObArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|  
|[CObArray::SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|  
  
### <a name="public-operators"></a>Operadores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CObArray::operator]](#operator_at)|Define ou obtém o elemento no índice especificado.|  
  
## <a name="remarks"></a>Comentários  
 Essas matrizes de objetos são semelhantes às matrizes de C, mas eles podem reduzir dinamicamente e cresça conforme necessário.  
  
 Índices de matriz sempre começam na posição 0. Você pode decidir se o limite superior de corrigir ou permitir que a matriz expandir quando você adiciona elementos após o limite atual. Memória está alocada continuamente o limite superior, mesmo que alguns elementos são nulos.  
  
 Sob Win32, o tamanho de um `CObArray` objeto é limitado somente a memória disponível.  
  
 Assim como acontece com uma matriz de C, o tempo de acesso para um `CObArray` elemento indexado é constante e é independente do tamanho da matriz.  
  
 A `CObArray` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Se uma matriz de `CObject` ponteiros são armazenados para um arquivo, com o operador sobrecarregado inserção ou com o `Serialize` função de membro, cada `CObject` elemento é, por sua vez, serializado junto com o índice de matriz.  
  
 Se você precisar de um despejo do indivíduo `CObject` elementos em uma matriz, você deve definir a profundidade do `CDumpContext` objeto como 1 ou maior.  
  
 Quando um `CObArray` objeto é excluído, ou quando seus elementos são removidos, somente o `CObject` ponteiros são removidos, não os objetos que eles fazem referência.  
  
> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 Derivação de classe de matriz é semelhante a derivação de lista. Para obter detalhes sobre a derivação de uma classe de lista de finalidade especial, consulte o artigo [coleções](../../mfc/collections.md).  
  
> [!NOTE]
>  Você deve usar o `IMPLEMENT_SERIAL` macro na implementação de sua classe derivada, se você pretende serializar a matriz.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CObArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
##  <a name="add"></a>  CObArray::Add  
 Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.  
  
```  
INT_PTR Add(CObject* newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `newElement`  
 O `CObject` ponteiro a ser adicionado a essa matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do elemento adicionado.  
  
### <a name="remarks"></a>Comentários  
 Se [SetSize](#setsize) foi usado com um `nGrowBy` valor maior que 1, em seguida, memória adicional pode ser alocado. No entanto, o limite superior aumentam em 1 somente.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Add`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**Adicionar INT_PTR (BYTE** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**Adicionar INT_PTR (DWORD** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**Adicionar INT_PTR (void\***  `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**Adicionar INT_PTR (LPCTSTR** `newElement` **); throw (CMemoryException\* );**<br /><br /> **INT_PTR Add(const CString&** `newElement` **);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**Adicionar INT_PTR (UINT** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**Adicionar INT_PTR (WORD** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
  
### <a name="example"></a>Exemplo  
  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#75](../../mfc/codesnippet/cpp/cobarray-class_1.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `Add example: A CObArray with 2 elements`  
  
 `[0] = a CAge at $442A 21`  
  
 `[1] = a CAge at $4468 40`  
  
##  <a name="append"></a>  CObArray::Append  
 Chame essa função de membro para adicionar o conteúdo de outro conjunto no final da matriz fornecida.  
  
```  
INT_PTR Append(const CObArray& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 Fonte dos elementos a serem acrescentados à matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do primeiro elemento anexado.  
  
### <a name="remarks"></a>Comentários  
 As matrizes devem ser do mesmo tipo.  
  
 Se necessário, **Append** pode alocar memória adicional para acomodar os elementos anexados à matriz.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Append`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**Acrescentar INT_PTR (const CByteArray &** *src* **);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**Acrescentar INT_PTR (const CDWordArray &** *src* **);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**Acrescentar INT_PTR (const CPtrArray &** *src* **);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**Acrescentar INT_PTR (const CStringArray &** *src* **);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**Acrescentar INT_PTR (const CUIntArray &** *src* **);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**Acrescentar INT_PTR (const CWordArray &** *src* **);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#76](../../mfc/codesnippet/cpp/cobarray-class_2.cpp)]  
  
##  <a name="copy"></a>  CObArray::Copy  
 Chame essa função de membro para substituir os elementos da matriz fornecida com os elementos da matriz outra do mesmo tipo.  
  
```  
void Copy(const CObArray& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 *src*  
 Fonte dos elementos a serem copiados para a matriz.  
  
### <a name="remarks"></a>Comentários  
 **Cópia** não libera memória; no entanto, se necessário, **cópia** pode alocar memória adicional para acomodar os elementos copiados para a matriz.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Copy`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**anular copiar (const CByteArray &** *src* **);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**anular copiar (const CDWordArray &** *src* **);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**anular copiar (const CPtrArray &** *src* **);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**anular copiar (const CStringArray &** *src* **);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**anular copiar (const CUIntArray &** *src* **);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**anular copiar (const CWordArray &** *src* **);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#77](../../mfc/codesnippet/cpp/cobarray-class_3.cpp)]  
  
##  <a name="cobarray"></a>  CObArray::CObArray  
 Constrói um vazio `CObject` matriz de ponteiro.  
  
```  
CObArray();
```  
  
### <a name="remarks"></a>Comentários  
 A matriz aumenta um elemento por vez.  
  
 A tabela a seguir mostra outros construtores que são semelhantes às `CObArray::CObArray`.  
  
|Classe|Construtor|  
|-----------|-----------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**() CByteArray;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**() CDWordArray;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**() CPtrArray;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**() CStringArray;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**() CUIntArray;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**() CWordArray;**|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCollections#78](../../mfc/codesnippet/cpp/cobarray-class_4.cpp)]  
  
##  <a name="elementat"></a>  CObArray::ElementAt  
 Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.  
  
```  
CObject*& ElementAt(INT_PTR nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um `CObject` ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Ele é usado para implementar o operador de atribuição da esquerda para matrizes. Observe que se trata de uma função avançada que deve ser usada somente para implementar operadores especiais de matriz.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::ElementAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**BYTES & ElementAt (INT_PTR** `nIndex` **);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**DWORD & ElementAt (INT_PTR** `nIndex` **);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\*& ElementAt (INT_PTR** `nIndex` **);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**CString & ElementAt (INT_PTR** `nIndex` **);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**UINT & ElementAt (INT_PTR** `nIndex` **);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**PALAVRA & ElementAt (INT_PTR** `nIndex` **);**|  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CObArray::GetSize](#getsize).  
  
##  <a name="freeextra"></a>  CObArray::FreeExtra  
 Libera qualquer memória extra que foi alocada enquanto a matriz foi aumentada.  
  
```  
void FreeExtra();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função não tem efeito sobre o tamanho ou o limite superior da matriz.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::FreeExtra`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void () FreeExtra;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void () FreeExtra;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void () FreeExtra;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void () FreeExtra;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void () FreeExtra;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void () FreeExtra;**|  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CObArray::GetData](#getdata).  
  
##  <a name="getat"></a>  CObArray::GetAt  
 Retorna o elemento de matriz no índice especificado.  
  
```  
CObject* GetAt(INT_PTR nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CObject` elemento ponteiro no momento nesse índice.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Passando um valor negativo ou um valor maior que o valor retornado por `GetUpperBound` resultará em uma declaração com falha.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**GetAt bytes (INT_PTR** `nIndex` **) const;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**GetAt DWORD (INT_PTR** `nIndex` **) const;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\* GetAt (INT_PTR** `nIndex` **) const;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**CString GetAt (INT_PTR** `nIndex` **) const;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**GetAt UINT (INT_PTR** `nIndex` **) const;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**WORD GetAt (INT_PTR** `nIndex` **) const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#79](../../mfc/codesnippet/cpp/cobarray-class_5.cpp)]  
  
##  <a name="getcount"></a>  CObArray::GetCount  
 Retorna o número de elementos da matriz.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na matriz.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de elementos na matriz. Como os índices com base em zero, o tamanho é maior que o maior índice de 1.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetCount`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**() GetCount INT_PTR const;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**() GetCount INT_PTR const;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**() GetCount INT_PTR const;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**() GetCount INT_PTR const;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**() GetCount INT_PTR const;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**() GetCount INT_PTR const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#80](../../mfc/codesnippet/cpp/cobarray-class_6.cpp)]  
  
##  <a name="getdata"></a>  CObArray::GetData  
 Use esta função de membro para obter acesso direto aos elementos na matriz.  
  
```  
const CObject** GetData() const;  
  
CObject** GetData();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a matriz de `CObject` ponteiros.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum elemento estiver disponível, `GetData` retorna um valor nulo.  
  
 Enquanto o acesso direto aos elementos de uma matriz pode ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao chamar `GetData`; os erros que você fizer diretamente afetam os elementos da sua matriz.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetData`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**BYTES const\* GetData () const; BYTES\* GetData (de);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**Const DWORD\* GetData () const; DWORD\* GetData (de);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void const\* \* (GetData) const; void\* \* GetData (de);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**Const CString\* GetData () const; CString\* GetData (de);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**UINT const\* GetData () const; UINT\* GetData (de);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**WORD const\* GetData () const; WORD\* GetData (de);**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#81](../../mfc/codesnippet/cpp/cobarray-class_7.cpp)]  
  
##  <a name="getsize"></a>  CObArray::GetSize  
 Retorna o tamanho da matriz.  
  
```  
INT_PTR GetSize() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Como os índices com base em zero, o tamanho é maior que o maior índice de 1.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetSize`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**() GetSize INT_PTR const;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**() GetSize INT_PTR const;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**() GetSize INT_PTR const;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**() GetSize INT_PTR const;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**() GetSize INT_PTR const;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**() GetSize INT_PTR const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#82](../../mfc/codesnippet/cpp/cobarray-class_8.cpp)]  
  
##  <a name="getupperbound"></a>  CObArray::GetUpperBound  
 Retorna o limite superior atual dessa matriz.  
  
```  
INT_PTR GetUpperBound() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do limite superior (com base em zero).  
  
### <a name="remarks"></a>Comentários  
 Como os índices de matriz são baseadas em zero, essa função retorna um valor de 1 menor `GetSize`.  
  
 A condição **(GetUpperBound)** = -1 indica que a matriz não contém elementos.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetUpperBound`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**() GetUpperBound INT_PTR const;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**() GetUpperBound INT_PTR const;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**() GetUpperBound INT_PTR const;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**() GetUpperBound INT_PTR const;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**() GetUpperBound INT_PTR const;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**() GetUpperBound INT_PTR const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#83](../../mfc/codesnippet/cpp/cobarray-class_9.cpp)]  
  
##  <a name="insertat"></a>  CObArray::InsertAt  
 Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.  
  
```  
void InsertAt(
    INT_PTR nIndex,  
    CObject* newElement,  
    INT_PTR nCount = 1);

 
void InsertAt(
    INT_PTR nStartIndex,  
    CObArray* pNewArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por `GetUpperBound`.  
  
 `newElement`  
 O `CObject` ponteiro sejam colocados nessa matriz. Um `newElement` do valor **nulo** é permitido.  
  
 `nCount`  
 O número de vezes que esse elemento deve ser inserido (o padrão é 1).  
  
 `nStartIndex`  
 Um índice de inteiro pode ser maior que o valor retornado por `GetUpperBound`.  
  
 `pNewArray`  
 Outra matriz que contém os elementos a serem adicionados a essa matriz.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `InsertAt` insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz. No processo, desloca para cima (aumentando o índice) do elemento existente nesse índice e desloca a todos os elementos acima dele.  
  
 A segunda versão insere todos os elementos de outro `CObArray` coleção, a partir de `nStartIndex` posição.  
  
 O `SetAt` função, por outro lado, substitui um elemento da matriz especificada e não deslocar a todos os elementos.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::InsertAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, BYTE** `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CByteArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, DWORD** `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CDWordArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, void\***  `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CPtrArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, LPCTSTR** `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CStringArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, UINT** `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CUIntArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void InsertAt (INT_PTR** `nIndex` **, WORD** `newElement` **, int** `nCount` **= 1);**<br /><br /> **Throw (CMemoryException\* );**<br /><br /> **void InsertAt (INT_PTR** `nStartIndex` **, CWordArray\***  `pNewArray` **);**<br /><br /> **Throw (CMemoryException\* );**|  
  
### <a name="example"></a>Exemplo  
  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#84](../../mfc/codesnippet/cpp/cobarray-class_10.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `InsertAt example: A CObArray with 3 elements`  
  
 `[0] = a CAge at $45C8 21`  
  
 `[1] = a CAge at $4646 30`  
  
 `[2] = a CAge at $4606 40`  
  
##  <a name="isempty"></a>  CObArray::IsEmpty  
 Determina se a matriz está vazia.  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a matriz está vazia. Caso contrário, 0.  
  
##  <a name="operator_at"></a>  [CObArray::operator]  
 Esses operadores subscript são um substituto conveniente para o `SetAt` e `GetAt` funções.  
  
```  
CObject*& operator[](int_ptr nindex);  
CObject* operator[](int_ptr nindex) const;  
```  
  
### <a name="remarks"></a>Comentários  
 O operador primeiro, chamado de matrizes que não são **const**, pode ser usado em à direita (r) ou à esquerda (l-value) de uma instrução de atribuição. A segunda chamada para **const** matrizes, pode ser usado somente no lado direito.  
  
 A versão de depuração da biblioteca declara se subscrito (tanto no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.  
  
 A tabela a seguir mostra os outros operadores que são semelhantes às **[CObArray::operator]**.  
  
|Classe|Operador|  
|-----------|--------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**[] Do operador & bytes (int_ptr** `nindex`  **\);**<br /><br /> **Operador BYTE [] (int_ptr** `nindex`  **\) const;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**[] Do operador & DWORD (int_ptr** `nindex`  **\);**<br /><br /> **DWORD operador [] (int_ptr** `nindex`  **\) const;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\*& operador [] (int_ptr** `nindex`  **\);**<br /><br /> **void\* operador [] (int_ptr** `nindex`  **\) const;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**[] CString & operador (int_ptr** `nindex`  **\);**<br /><br /> **CString operador [] (int_ptr** `nindex`  **\) const;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**[] Do operador & UINT (int_ptr** `nindex`  **\);**<br /><br /> **UINT operador [] (int_ptr** `nindex`  **\) const;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**[] Do operador & WORD (int_ptr** `nindex`  **\);**<br /><br /> **WORD operador [] (int_ptr** `nindex`  **\) const;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#88](../../mfc/codesnippet/cpp/cobarray-class_11.cpp)]  
  
##  <a name="removeall"></a>  CObArray::RemoveAll  
 Remove todos os ponteiros dessa matriz, mas, na verdade, não exclui o `CObject` objetos.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Se a matriz estiver vazia, a função ainda funciona.  
  
 O `RemoveAll` função libera toda a memória usada para o armazenamento de ponteiro.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::RemoveAll`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void () RemoveAll;**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void () RemoveAll;**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void () RemoveAll;**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void () RemoveAll;**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void () RemoveAll;**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void () RemoveAll;**|  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#85](../../mfc/codesnippet/cpp/cobarray-class_12.cpp)]  
  
##  <a name="removeat"></a>  CObArray::RemoveAt  
 Remove um ou mais elementos, começando em um índice especificado em uma matriz.  
  
```  
void RemoveAt(
    INT_PTR nIndex,  
    INT_PTR nCount = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.  
  
 `nCount`  
 O número de elementos a serem removidos.  
  
### <a name="remarks"></a>Comentários  
 O processo, ele muda para baixo de todos os elementos acima do elemento removido (s). Ele diminui a superior associado da matriz, mas não libera memória.  
  
 Se você tentar remover mais elementos que estão contidos na matriz acima do ponto de remoção, declara a versão de depuração da biblioteca.  
  
 O `RemoveAt` função remove o `CObject` ponteiro de matriz, mas ele não exclui o objeto propriamente dito.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::RemoveAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void RemoveAt (INT_PTR** `nIndex` **, INT_PTR** *nCount* **= 1);**|  
  
### <a name="example"></a>Exemplo  
  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#112](../../mfc/codesnippet/cpp/cobarray-class_13.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `RemoveAt example: A CObArray with 1 elements`  
  
 `[0] = a CAge at $4606 40`  
  
##  <a name="setat"></a>  CObArray::SetAt  
 Define o elemento de matriz no índice especificado.  
  
```  
void SetAt(
    INT_PTR nIndex,  
    CObject* newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.  
  
 `newElement`  
 O ponteiro de objeto a ser inserido nesta matriz. Um **nulo** valor permitido.  
  
### <a name="remarks"></a>Comentários  
 `SetAt` não fará com que a matriz de crescimento. Use `SetAtGrow` se você quiser que a matriz para crescer automaticamente.  
  
 Certifique-se de que o valor de índice representa uma posição válida na matriz. Se ele está fora dos limites, declara a versão de depuração da biblioteca.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetAt`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetAt (INT_PTR** `nIndex` **, BYTE** `newElement` **);**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, DWORD** `newElement` **);**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, void\***  `newElement` **);**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, LPCTSTR** `newElement` **);**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, UINT** `newElement` **);**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, WORD** `newElement` **);**|  
  
### <a name="example"></a>Exemplo  
  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#86](../../mfc/codesnippet/cpp/cobarray-class_14.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `SetAt example: A CObArray with 2 elements`  
  
 `[0] = a CAge at $47E0 30`  
  
 `[1] = a CAge at $47A0 40`  
  
##  <a name="setatgrow"></a>  CObArray::SetAtGrow  
 Define o elemento de matriz no índice especificado.  
  
```  
void SetAtGrow(
    INT_PTR nIndex,  
    CObject* newElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Um índice de inteiro que é maior que ou igual a 0.  
  
 `newElement`  
 O ponteiro de objeto a ser adicionado a essa matriz. Um **nulo** valor permitido.  
  
### <a name="remarks"></a>Comentários  
 A matriz cresce automaticamente se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetAtGrow`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, BYTE** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, DWORD** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, void\***  `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, LPCTSTR** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, UINT** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, WORD** `newElement` **);**<br /><br /> **Throw (CMemoryException\* );**|  
  
### <a name="example"></a>Exemplo  
  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.  
  
 [!code-cpp[NVC_MFCCollections#87](../../mfc/codesnippet/cpp/cobarray-class_15.cpp)]  
  
 Os resultados desse programa são da seguinte maneira:  
  
 `SetAtGrow example: A CObArray with 4 elements`  
  
 `[0] = a CAge at $47C0 21`  
  
 `[1] = a CAge at $4800 40`  
  
 `[2] = NULL`  
  
 `[3] = a CAge at $4840 65`  
  
##  <a name="setsize"></a>  CObArray::SetSize  
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
 Se o novo tamanho for menor que o tamanho anterior, em seguida, a matriz será truncada e não utilizada toda a memória é liberada. Para eficiência, chame `SetSize` para definir o tamanho da matriz antes de usá-lo. Isso evita a necessidade de realocar e copiar a matriz sempre que um item é adicionado.  
  
 O `nGrowBy` parâmetro afeta a alocação de memória interna enquanto a matriz está aumentando. Seu uso não afeta o tamanho da matriz conforme relatado pelo `GetSize` e `GetUpperBound`.  
  
 Se o tamanho da matriz cresceu, todos os novos alocado **CObject \***  ponteiros são definidos como NULL.  
  
 A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetSize`.  
  
|Classe|Função membro|  
|-----------|---------------------|  
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetSize (INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1);**<br /><br /> **Throw (CMemoryException\* );**|  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CObArray::GetData](#getdata).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CStringArray](../../mfc/reference/cstringarray-class.md)   
 [Classe CPtrArray](../../mfc/reference/cptrarray-class.md)   
 [Classe CByteArray](../../mfc/reference/cbytearray-class.md)   
 [Classe CWordArray](../../mfc/reference/cwordarray-class.md)   
 [Classe CDWordArray](../../mfc/reference/cdwordarray-class.md)
