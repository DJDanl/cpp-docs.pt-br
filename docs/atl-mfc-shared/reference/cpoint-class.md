---
title: Classe CPoint | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CPoint
- ATLTYPES/ATL::CPoint
- ATLTYPES/ATL::CPoint::CPoint
- ATLTYPES/ATL::CPoint::Offset
dev_langs:
- C++
helpviewer_keywords:
- LPPOINT structure
- POINT structure
- CPoint class
ms.assetid: a6d4db93-35cc-444d-9221-c3e160f6edaa
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7140e2db55db8a28c1af63f89517708f4dc0d835
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cpoint-class"></a>Classe CPoint
Semelhante do Windows `POINT` estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPoint : public tagPOINT 
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPoint::CPoint](#cpoint)|Constrói um `CPoint`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPoint::Offset](#offset)|Adiciona os valores para o **x** e **y** membros a `CPoint`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPoint::operator-](#operator_-)|Retorna a diferença entre um `CPoint` e um tamanho ou a negação de um ponto ou a diferença de tamanho entre dois pontos ou o deslocamento de um tamanho negativo.|  
|[CPoint::operator! =](#operator_neq)|Verifica a desigualdade entre dois pontos.|  
|[CPoint::operator +](#operator_add)|Retorna a soma de um `CPoint` e um tamanho ou o ponto ou um `CRect` por um tamanho de deslocamento.|  
|[+ CPoint::operator =](#operator_add_eq)|Desloca `CPoint` adicionando um tamanho ou um ponto.|  
|[CPoint::operator =](#operator_-_eq)|Desloca `CPoint` subtraindo-se um tamanho ou um ponto.|  
|[CPoint::operator = =](#operator_eq_eq)|Verificações de igualdade entre dois pontos.|  
  
## <a name="remarks"></a>Comentários  
 Ele também inclui funções de membro para manipular `CPoint` e [ponto](../../mfc/reference/point-structure1.md) estruturas.  
  
 Um `CPoint` objeto pode ser usado sempre que um `POINT` estrutura é usada. Os operadores que interagem com um tamanho de"" desta classe aceitam um [CSize](../../atl-mfc-shared/reference/csize-class.md) objetos ou [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estruturas, desde que os dois são intercambiáveis.  
  
> [!NOTE]
>  Essa classe é derivada do `tagPOINT` estrutura. (O nome `tagPOINT` é um nome usado com menos frequência para o `POINT` estrutura.) Isso significa que os membros de dados de `POINT` estrutura, `x` e `y`, são membros de dados acessível `CPoint`.  
  
> [!NOTE]
>  Para obter mais informações sobre classes de utilitário de compartilhados (como `CPoint`), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagPOINT`  
  
 `CPoint`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltypes.h  
  
##  <a name="cpoint"></a>CPoint::CPoint
 Constrói um objeto `CPoint`.  
  
```  
CPoint() throw();
CPoint(int initX, int initY) throw();
CPoint(POINT initPt) throw();
CPoint(SIZE initSize) throw();
CPoint(LPARAM dwPoint) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `initX`  
 Especifica o valor do membro `x` de `CPoint`.  
  
 `initY`  
 Especifica o valor do membro `y` de `CPoint`.  
  
 `initPt`  
 [PONTO](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` que especifica os valores usados para inicializar `CPoint`.  
  
 `initSize`  
 [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica os valores usados para inicializar `CPoint`.  
  
 `dwPoint`  
 Define o membro `x` como a palavra de ordem inferior de `dwPoint` e o membro `y` como a palavra de ordem superior de `dwPoint`.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, os membros `x` e `y` serão definidos como 0.  
  
### <a name="example"></a>Exemplo  
  
```cpp   
CPoint   ptTopLeft(0, 0); 
// works from a POINT, too  
 
POINT   ptHere;  
ptHere.x = 35;  
ptHere.y = 95;  
 
CPoint   ptMFCHere(ptHere);
 
// works from a SIZE 
SIZE   sHowBig;  
sHowBig.cx = 300;  
sHowBig.cy = 10;  
 
CPoint ptMFCBig(sHowBig); 
// or from a DWORD  
 
DWORD   dwSize;  
dwSize = MAKELONG(35, 95);
 
CPoint ptFromDouble(dwSize);
ASSERT(ptFromDouble == ptMFCHere);
```  
  
##  <a name="offset"></a>CPoint::Offset  
 Adiciona os valores para o **x** e **y** membros a `CPoint`.  
  
```  
void Offset(int xOffset, int yOffset) throw();
void Offset(POINT point) throw();
void Offset(SIZE size) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *deslocamento x*  
 Especifica a quantidade para deslocar o **x** membro o `CPoint`.  
  
 *deslocamento y*  
 Especifica a quantidade para deslocar o **y** membro o `CPoint`.  
  
 `point`  
 Especifica a quantidade ( [ponto](../../mfc/reference/point-structure1.md) ou `CPoint`) para compensar a `CPoint`.  
  
 `size`  
 Especifica a quantidade ( [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](../../atl-mfc-shared/reference/csize-class.md)) para compensar a `CPoint`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#28](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_1.cpp)]  
  
##  <a name="operator_eq_eq"></a>CPoint::operator = =  
 Verificações de igualdade entre dois pontos.  
  
```  
BOOL operator==(POINT point) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os pontos forem iguais; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#29](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_2.cpp)]  
  
##  <a name="operator_neq"></a>CPoint::operator! =  
 Verifica a desigualdade entre dois pontos.  
  
```  
BOOL operator!=(POINT point) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os pontos não são iguais; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#30](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_3.cpp)]  
  
##  <a name="operator_add_eq"></a>+ CPoint::operator =  
 A primeira sobrecarga adiciona um tamanho para o `CPoint`.  
  
```  
void operator+=(SIZE size) throw(); 
void operator+=(POINT point) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Contém uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A segunda sobrecarga adiciona um ponto para o `CPoint`.  
  
 Em ambos os casos, a adição é feita adicionando o **x** (ou **cx**) membro do operando direito para o **x** membro do `CPoint` e adicionando o **y**  (ou **cy**) membro do operando direito para o **y** membro o `CPoint`.  
  
 Por exemplo, adicionando `CPoint(5, -7)` a uma variável que contém `CPoint(30, 40)` altera a variável `CPoint(35, 33)`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#31](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_4.cpp)]  
  
##  <a name="operator_-_eq"></a>CPoint::operator =  
 A primeira sobrecarga subtrai um tamanho do `CPoint`.  
  
```  
void operator-=(SIZE size) throw(); 
void operator-=(POINT point) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Contém uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A segunda sobrecarga subtrai um ponto a partir de `CPoint`.  
  
 Em ambos os casos, subtração é feita subtraindo o **x** (ou **cx**) membro do operando direito do **x** membro do `CPoint` e subtraindo o **y** (ou **cy**) membro do operando direito do **y** membro o `CPoint`.  
  
 Por exemplo, subtraindo `CPoint(5, -7)` de uma variável que contém `CPoint(30, 40)` altera a variável `CPoint(25, 47)`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#32](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_5.cpp)]  
  
##  <a name="operator_add"></a>CPoint::operator +  
 Use este operador para deslocar `CPoint` por um `CPoint` ou `CSize` objeto, ou para deslocar um `CRect` por um `CPoint`.  
  
```  
CPoint operator+(SIZE size) const throw();
CPoint operator+(POINT point) const throw();
CRect operator+(const RECT* lpRect) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Contém uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
 `point`  
 Contém uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
 `lpRect`  
 Contém um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CPoint` que tem um deslocamento de um tamanho, uma **CPoint** que tem um deslocamento de um ponto ou um **CRect** deslocamento por um ponto.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, usando uma das duas primeiras sobrecargas para deslocar o ponto `CPoint(25, -19)` por um ponto de `CPoint(15, 5)` ou tamanho `CSize(15, 5)` retorna o valor `CPoint(40, -14)`.  
  
 Adicionar um retângulo a um ponto retorna o retângulo após sendo deslocado pelo **x** e **y** valores especificados no ponto. Por exemplo, usando a última sobrecarga para deslocar um retângulo `CRect(125, 219, 325, 419)` por um ponto de `CPoint(25, -19)` retorna `CRect(150, 200, 350, 400)`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#33](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_6.cpp)]  
  
##  <a name="operator_-"></a>CPoint::operator-  
 Use uma das primeiras duas sobrecargas para subtrair um `CPoint` ou `CSize` de objeto `CPoint`.  
  
```  
CSize operator-(POINT point) const throw();
CPoint operator-(SIZE size) const throw();
CRect operator-(const RECT* lpRect) const throw();
CPoint operator-() const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Um [ponto](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
 `size`  
 Um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
 `lpRect`  
 Um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` que é a diferença entre dois pontos, uma `CPoint` que tem um deslocamento de negação de tamanho, um `CRect` que tem um deslocamento de negação de um ponto ou um `CPoint` que é a negação de um ponto.  
  
### <a name="remarks"></a>Comentários  
 A terceira sobrecarga deslocamentos um `CRect` por negação de `CPoint`. Por fim, use o operador unário para negar `CPoint`.  
  
 Por exemplo, usando a primeira sobrecarga para localizar a diferença entre dois pontos `CPoint(25, -19)` e `CPoint(15, 5)` retorna `CSize(10, -24)`.  
  
 Subtrair um `CSize` de `CPoint` não o mesmo cálculo como acima, mas retorna um `CPoint` do objeto, não um `CSize` objeto. Por exemplo, usando a segunda sobrecarga para localizar a diferença entre o ponto de `CPoint(25, -19)` e o tamanho `CSize(15, 5)` retorna `CPoint(10, -24)`.  
  
 Subtração de um retângulo de um ponto de retorna o deslocamento do retângulo por negativos do **x** e **y** valores especificados no ponto. Por exemplo, usando a última sobrecarga para deslocar o retângulo `CRect(125, 200, 325, 400)` pelo ponto de `CPoint(25, -19)` retorna `CRect(100, 219, 300, 419)`.  
  
 Use o operador unário para negar um ponto. Por exemplo, usando o operador unário com o ponto de `CPoint(25, -19)` retorna `CPoint(-25, 19)`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#34](../../atl-mfc-shared/codesnippet/cpp/cpoint-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura POINT](../../mfc/reference/point-structure1.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)   
 [Classe CSize](../../atl-mfc-shared/reference/csize-class.md)



