---
title: Classe CSize | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSize
dev_langs:
- C++
helpviewer_keywords:
- SIZE
- dimensions, MFC
- dimensions
- CSize class
ms.assetid: fb2cf85a-0bc1-46f8-892b-309c108b52ae
caps.latest.revision: 20
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 96905d916dfde8f8a7bf8131a280ae7ccfe511d8
ms.lasthandoff: 02/25/2017

---
# <a name="csize-class"></a>Classe CSize
Semelhante do Windows [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura, que implementa uma coordenada relativa ou posição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSize : public tagSIZE 
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSize::CSize](#csize)|Constrói um objeto `CSize`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSize::operator-](#operator_-)|Subtrai dois tamanhos.|  
|[CSize::operator! =](#operator_neq)|Verifica a desigualdade entre `CSize` e um tamanho.|  
|[CSize::operator +](#operator_add)|Adiciona dois tamanhos.|  
|[+ = CSize::operator](#operator_add_eq)|Adiciona um tamanho para `CSize`.|  
|[CSize::operator =](#operator_-_eq)|Subtrai um tamanho de `CSize`.|  
|[CSize::operator = =](#operator_eq_eq)|Verificações de igualdade entre `CSize` e um tamanho.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é derivada do **tamanho** estrutura. Isso significa que você pode passar um `CSize` em um parâmetro que chama uma **tamanho** e que os membros de dados de **tamanho** estrutura são membros de dados acessíveis de `CSize`.  
  
 O **cx** e **cy** membros da **tamanho** (e `CSize`) são públicos. Além disso, `CSize` implementa as funções de membro para manipular o **tamanho** estrutura.  
  
> [!NOTE]
>  Para obter mais informações sobre classes de utilitário de compartilhado (como `CSize`), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagSIZE`  
  
 `CSize`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltypes. h  
  
##  <a name="a-namecsizea--csizecsize"></a><a name="csize"></a>CSize::CSize  
 Constrói um objeto `CSize`.  
  
```  
CSize() throw();
CSize( int initCX, int initCY) throw();
CSize( SIZE initSize) throw();
CSize( POINT initPt) throw();
CSize( DWORD dwSize) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *initCX*  
 Conjuntos de **cx** membro para o `CSize`.  
  
 *initCY*  
 Conjuntos de **cy** membro para o `CSize`.  
  
 `initSize`  
 [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou `CSize` objeto usado para inicializar `CSize`.  
  
 `initPt`  
 [PONTO](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto usado para inicializar `CSize`.  
  
 `dwSize`  
 `DWORD`usado para inicializar `CSize`. A palavra de ordem inferior é o **cx** membro e a palavra de ordem superior é o **cy** membro.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, **cx** e **cy** são inicializados em zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#97;](../../atl-mfc-shared/codesnippet/cpp/csize-class_1.cpp)]  
  
##  <a name="a-nameoperatoreqeqa--csizeoperator-"></a><a name="operator_eq_eq"></a>CSize::operator = =  
 Verificações de igualdade entre dois tamanhos.  
  
```   
BOOL operator==(SIZE size) const throw(); 
```  
  
### <a name="remarks"></a>Comentários  
 Retorna zero se os tamanhos forem iguais, otherwize 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#98;](../../atl-mfc-shared/codesnippet/cpp/csize-class_2.cpp)]  
  
##  <a name="a-nameoperatorneqa--csizeoperator-"></a><a name="operator_neq"></a>CSize::operator! =  
 Verificações de desigualdade entre dois tamanhos.  
  
```   
BOOL operator!=(SIZE size) const throw(); 
```  
  
### <a name="remarks"></a>Comentários  
 Retorna zero se os tamanhos não forem iguais, caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#99;](../../atl-mfc-shared/codesnippet/cpp/csize-class_3.cpp)]  
  
##  <a name="a-nameoperatoraddeqa--csizeoperator-"></a><a name="operator_add_eq"></a>+ = CSize::operator  
 Isso adiciona um tamanho `CSize`.  
  
```   
void operator+=(SIZE size) throw(); 
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#100;](../../atl-mfc-shared/codesnippet/cpp/csize-class_4.cpp)]  
  
##  <a name="a-nameoperator-eqa--csizeoperator--"></a><a name="operator_-_eq"></a>CSize::operator =  
 Subtrai um tamanho neste `CSize`.  
  
```   
void operator-=(SIZE size) throw(); 
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#101;](../../atl-mfc-shared/codesnippet/cpp/csize-class_5.cpp)]  
  
##  <a name="a-nameoperatoradda--csizeoperator-"></a><a name="operator_add"></a>CSize::operator +  
 Adicione esses operadores `CSize` valor para o valor do parâmetro.  
  
```   
CSize operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw(); 
```  
  
### <a name="remarks"></a>Comentários  
 Consulte as seguintes descrições dos operadores individuais:  
  
- **operador + (** `size` **)**essa operação adiciona dois `CSize` valores.  
  
- **operador + (** `point` **)**essa operação deslocamentos (se move) um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) (ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md)) valor nisso `CSize` valor. O **cx** e **cy** membros desse `CSize` valor são adicionados para o **x** e **y** membros de dados a **ponto** valor. Ele é semelhante à versão do [CPoint::operator +](../../atl-mfc-shared/reference/cpoint-class.md#operator_add) que usa um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.  
  
- **operador + (** `lpRect` **)**essa operação deslocamentos (se move) um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) (ou [CRect](../../atl-mfc-shared/reference/crect-class.md)) valor nisso `CSize` valor. O **cx** e **cy** membros desse `CSize` valor são adicionados ao **esquerda**, **superior**, **direita**, e **inferior** membros de dados a `RECT` valor. Ele é semelhante à versão do [CRect::operator +](../../atl-mfc-shared/reference/crect-class.md#operator_add) que usa um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#102;](../../atl-mfc-shared/codesnippet/cpp/csize-class_6.cpp)]  
  
##  <a name="a-nameoperator-a--csizeoperator--"></a><a name="operator_-"></a>CSize::operator-  
 Os primeiros três desses operadores subtrair isso `CSize` valor para o valor do parâmetro.  
  
```   
CSize operator-(SIZE size) const throw();
CPoint operator-(POINT point) const throw();
CRect operator-(const RECT* lpRect) const throw();
CSize operator-() const throw(); 
```  
  
### <a name="remarks"></a>Comentários  
 O quarto operador, o operador unário menos, altera o sinal do `CSize` valor. Consulte as seguintes descrições dos operadores individuais:  
  
- **operador-(** `size` **)**essa operação subtrai dois `CSize` valores.  
  
- **operador-(** `point` **)**essa operação deslocamentos (se move) um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) valor, o inverso aditivo isso `CSize` valor. O **cx** e **cy** deste `CSize` valor são subtraídos do **x** e **y** membros de dados de **ponto** valor. Ele é semelhante à versão do [CPoint::operator -](../../atl-mfc-shared/reference/cpoint-class.md#operator_-) que usa um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.  
  
- **operador-(** `lpRect` **)**essa operação deslocamentos (se move) um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) valor, o inverso aditivo isso `CSize` valor. O **cx** e **cy** membros deste `CSize` valor são subtraídos do **esquerda**, **superior**, **direita**, e **inferior** membros de dados a `RECT` valor. Ele é semelhante à versão do [CRect::operator -](../../atl-mfc-shared/reference/crect-class.md#operator_-) que usa um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) parâmetro.  
  
- **operador-()**esta operação retorna o inverso aditivo isso `CSize` valor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#103;](../../atl-mfc-shared/codesnippet/cpp/csize-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)   
 [Classe CPoint](../../atl-mfc-shared/reference/cpoint-class.md)


