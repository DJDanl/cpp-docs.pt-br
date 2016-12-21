---
title: "Classe CRect | Microsoft Docs"
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
  - "CRect"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Tipo de dados LPCRECT"
  - "Classe CRect"
  - "Operador LPRECT"
  - "Estrutura RECT"
ms.assetid: dee4e752-15d6-4db4-b68f-1ad65b2ed6ca
caps.latest.revision: 24
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CRect
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Semelhante a um Windows [RECT](RECT%20Structure1.md) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRect : public tagRECT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::CRect](#crect__crect)|Constrói um objeto `CRect`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::BottomRight](#crect__bottomright)|Retorna o ponto de canto direito inferior do `CRect`.|  
|[CRect::CenterPoint](#crect__centerpoint)|Retorna o PontoCentral de `CRect`.|  
|[CRect::CopyRect](#crect__copyrect)|Copia as dimensões de um retângulo de origem para `CRect`.|  
|[CRect::DeflateRect](#crect__deflaterect)|Reduz a largura e altura de `CRect`.|  
|[CRect::EqualRect](#crect__equalrect)|Determina se `CRect` é igual ao retângulo determinado.|  
|[CRect::Height](#crect__height)|Calcula a altura de `CRect`.|  
|[CRect::InflateRect](#crect__inflaterect)|Aumenta a largura e altura de `CRect`.|  
|[CRect::IntersectRect](#crect__intersectrect)|Conjuntos de `CRect` igual a interseção de dois retângulos.|  
|[CRect::IsRectEmpty](#crect__isrectempty)|Determina se `CRect` está vazia. `CRect` está vazio se a altura e/ou largura forem 0.|  
|[CRect::IsRectNull](#crect__isrectnull)|Determina se o **superior**, **inferior**, **esquerda**, e **direita** variáveis de membros são todos iguais a 0.|  
|[CRect::MoveToX](#crect__movetox)|Move `CRect` para a coordenada x especificada.|  
|[CRect::MoveToXY](#crect__movetoxy)|Move `CRect` para coordenadas x e y especificadas.|  
|[CRect::MoveToY](#crect__movetoy)|Move `CRect` para a coordenada y especificada.|  
|[CRect::NormalizeRect](#crect__normalizerect)|Padroniza a altura e largura do `CRect`.|  
|[CRect::OffsetRect](#crect__offsetrect)|Move `CRect` pelos deslocamentos especificados.|  
|[CRect::PtInRect](#crect__ptinrect)|Determina se o ponto especificado está em `CRect`.|  
|[CRect::SetRect](#crect__setrect)|Define as dimensões de `CRect`.|  
|[CRect::SetRectEmpty](#crect__setrectempty)|Conjuntos de `CRect` um retângulo vazio (todas as coordenadas igual a 0).|  
|[CRect::Size](#crect__size)|Calcula o tamanho da `CRect`.|  
|[CRect::SubtractRect](#crect__subtractrect)|Subtrai um retângulo de outro.|  
|[CRect::TopLeft](#crect__topleft)|Retorna o ponto do canto superior esquerdo do `CRect`.|  
|[CRect::UnionRect](#crect__unionrect)|Conjuntos de `CRect` igual a união de dois retângulos.|  
|[CRect::Width](#crect__width)|Calcula a largura do `CRect`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRect::operator-](#crect__operator_-)|Subtrai os deslocamentos determinados de `CRect` ou esvaziamento `CRect` e retorna resultante `CRect`.|  
|[CRect::operator LPCRECT](#crect__operator_lpcrect)|Converte um `CRect` para um **LPCRECT**.|  
|[CRect::operator LPRECT](#crect__operator_lprect)|Converte um `CRect` para um `LPRECT`.|  
|[CRect::operator! =](#crect__operator__neq)|Determina se `CRect` não é igual a um retângulo.|  
|[CRect::operator &amp;](#crect__operator__amp_)|Cria a interseção de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator &amp;=](#crect__operator__amp__eq)|Conjuntos de `CRect` igual a interseção de `CRect` e um retângulo.|  
|[CRect::operator |](#crect__operator__or)|Cria a união de `CRect` e um retângulo e retorna resultante `CRect`.|  
|[CRect::operator |=](#crect__operator__or_eq)|Conjuntos de `CRect` igual a união de `CRect` e um retângulo.|  
|[CRect::operator +](#crect__operator__add)|Adiciona os deslocamentos determinados para `CRect` ou inflar `CRect` e retorna resultante `CRect`.|  
|[+ = CRect::operator](#crect__operator__add_eq)|Adiciona os deslocamentos especificados para `CRect` ou inflar `CRect`.|  
|[CRect::operator =](#crect__operator__eq)|Copia as dimensões de um retângulo para `CRect`.|  
|[CRect::operator =](#crect__operator_-_eq)|Subtrai os deslocamentos especificados de `CRect` ou esvaziamento `CRect`.|  
|[CRect::operator = =](#crect__operator__eq_eq)|Determina se `CRect` é igual a um retângulo.|  
  
## <a name="remarks"></a>Comentários  
 `CRect` também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.  
  
 Um `CRect` objeto pode ser passado como um parâmetro de função sempre que um `RECT` estrutura, **LPCRECT**, ou `LPRECT` pode ser passado.  
  
> [!NOTE]
>  Essa classe é derivada do **tagRECT** estrutura. (O nome **tagRECT** é um nome menor usados para o `RECT` estrutura.) Isso significa que os membros de dados ( **esquerda**, **superior**, **direita**, e **inferior**) do `RECT` estrutura são membros de dados acessíveis de `CRect`.  
  
 A `CRect` contém variáveis de membro que definem os pontos superior esquerda e direita de um retângulo.  
  
 Ao especificar um `CRect`, você deve ter cuidado para construí-la para que ele é normalizado — em outras palavras, que o valor da coordenada esquerda é inferior à direita e a parte superior é menor que a parte inferior. Por exemplo, um superior esquerda do (10,10) e inferior direita da (20,20) define um retângulo normalizado, mas um superior esquerda do (20,20) e inferior direita da (10,10) define um retângulo não normalizado. Se o retângulo não normalizado, muitos `CRect` funções de membro podem retornar resultados incorretos. (Consulte [CRect::NormalizeRect](#crect__normalizerect) para obter uma lista dessas funções.) Antes de chamar uma função que requer normalizados retângulos, você pode normalizar retângulos não normalizado chamando o `NormalizeRect` função.  
  
 Tenha cuidado ao manipular um `CRect` com [CDC::DPtoLP] (... /Topic/CDC%20Class.MD#cdc__dptolp e [CDC::LPtoDP] (... Funções de membro /Topic/CDC%20Class.MD#cdc__lptodp. Se o modo de mapeamento de um contexto de exibição é que a extensão de y for negativa, como em `MM_LOENGLISH`, em seguida, `CDC::DPtoLP` transformará o `CRect` para que a parte superior é maior que a parte inferior. Funções como **Altura** e **tamanho** retornará valores negativos para a altura da transformado `CRect`, e o retângulo estará não normalizado.  
  
 Quando uso sobrecarregado `CRect` operadores, o primeiro operando deve ser um `CRect`; o segundo pode ser um [RECT](RECT%20Structure1.md) estrutura ou um `CRect` objeto.  
  
> [!NOTE]
>  Para obter mais informações sobre classes de utilitário de compartilhado (como `CRect`), consulte [Classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagRECT`  
  
 `CRect`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltypes. h  
  
##  <a name="a-namecrectbottomrighta-crectbottomright"></a><a name="crect__bottomright"></a>  CRect::BottomRight  
 As coordenadas são retornadas como uma referência a um [CPoint](../Topic/CPoint%20Class.md) contido no objeto `CRect`.  
  
```  
 
CPoint& BottomRight() throw();

const CPoint& BottomRight() const throw();

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto inferior direito do retângulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para obter ou definir o canto inferior direito do retângulo. Defina o canto usando essa função no lado esquerdo do operador de atribuição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#35](../../atl-mfc-shared/codesnippet/CPP/crect-class_1.cpp)]  
  
##  <a name="a-namecrectcenterpointa-crectcenterpoint"></a><a name="crect__centerpoint"></a>  CRect::CenterPoint  
 Calcula o PontoCentral de `CRect` adicionando os valores de esquerda e direito e dividindo por dois e adicionando os valores superior e inferior e dividindo por dois.  
  
```  
CPoint CenterPoint() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CPoint` objeto PontoCentral de `CRect`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#36](../../atl-mfc-shared/codesnippet/CPP/crect-class_2.cpp)]  
  
##  <a name="a-namecrectcopyrecta-crectcopyrect"></a><a name="crect__copyrect"></a>  CRect::CopyRect  
 Copia o `lpSrcRect` retângulo em `CRect`.  
  
```  
 
void CopyRect(
LPCRECT   
lpSrcRect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSrcRect`  
 Aponta para a [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto a ser copiado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#37](../../atl-mfc-shared/codesnippet/CPP/crect-class_3.cpp)]  
  
##  <a name="a-namecrectcrecta-crectcrect"></a><a name="crect__crect"></a>  CRect::CRect  
 Constrói um objeto `CRect`.  
  
```  
 
    CRect() throw();
CRect(
 int    
    l ,  
    int 
    t ,  
    int 
    r ,  
    int 
    b) throw();
CRect(
 const RECT& 
    srcRect) throw();
CRect(
 LPCRECT    
    lpSrcRect) throw();
CRect(
 POINT    
    point ,  
    SIZE 
    size) throw();
CRect(
 POINT    
    topLeft ,  
    POINT 
    bottomRight) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *l*  
 Especifica a posição esquerda do `CRect`.  
  
 *t*  
 Especifica a parte superior do `CRect`.  
  
 *r*  
 Especifica a posição direita da `CRect`.  
  
 *b*  
 Especifica a parte inferior da `CRect`.  
  
 *srcRect*  
 Refere-se para o [RECT](RECT%20Structure1.md) estrutura com as coordenadas para `CRect`.  
  
 `lpSrcRect`  
 Aponta para a `RECT` estrutura com as coordenadas para `CRect`.  
  
 `point`  
 Especifica o ponto de origem para o retângulo para ser criada. Corresponde ao canto superior esquerdo.  
  
 `size`  
 Especifica o deslocamento do canto superior esquerdo para o canto inferior direito do retângulo para ser criada.  
  
 *topLeft*  
 Especifica a posição do canto superior esquerdo do `CRect`.  
  
 *bottomRight*  
 Especifica a posição do canto direito inferior do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, **esquerda**, **superior**, **direita**, e **inferior** membros não são inicializados.  
  
 O `CRect`( **RECT const &**) e `CRect`( **LPCRECT**) construtores realizar uma [CopyRect](#crect__copyrect). Construtores de inicializam as variáveis de membro do objeto diretamente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#38](../../atl-mfc-shared/codesnippet/CPP/crect-class_4.cpp)]  
  
##  <a name="a-namecrectdeflaterecta-crectdeflaterect"></a><a name="crect__deflaterect"></a>  CRect::DeflateRect  
 `DeflateRect` esvazia `CRect` movendo suas laterais em direção ao centro.  
  
```  
 
    void DeflateRect(
    int 
    x ,  
    int 
    y) throw();
void DeflateRect(
    SIZE 
    size) throw();
void DeflateRect(
    LPCRECT 
    lpRect) throw();
void DeflateRect(
    int 
    l ,  
    int 
    t ,  
    int 
    r ,  
    int 
    b) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para deflate à esquerda e à direita do `CRect`.  
  
 *y*  
 Especifica o número de unidades de deflate superior e inferior de `CRect`.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o número de unidades para deflate `CRect`. O `cx` valor Especifica o número de unidades para deflate à esquerda e à direita e o `cy` valor Especifica o número de unidades para deflate nas partes superior e inferior.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` que especifica o número de unidades para deflate cada lado.  
  
 *l*  
 Especifica o número de unidades de deflate à esquerda do `CRect`.  
  
 *t*  
 Especifica o número de unidades de deflate parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades de deflate à direita do `CRect`.  
  
 *b*  
 Especifica o número de unidades de deflate parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `DeflateRect` adiciona unidades à esquerda e superior e subtrai unidades a parte inferior e direita. Os parâmetros de `DeflateRect` assinadas valores; valores positivos deflate `CRect` e valores negativos aumentar a ele.  
  
 As primeiras duas sobrecargas deflate dois pares de lados opostos `CRect` para que sua largura total será diminuída em duas vezes *x* (ou `cx`) e sua altura total será diminuída em duas vezes *y* (ou `cy`). As duas sobrecargas deflate cada lado da `CRect` independentemente dos outros.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#39](../../atl-mfc-shared/codesnippet/CPP/crect-class_5.cpp)]  
  
##  <a name="a-namecrectequalrecta-crectequalrect"></a><a name="crect__equalrect"></a>  CRect::EqualRect  
 Determina se `CRect` é igual ao retângulo determinado.  
  
```  
 
BOOL EqualRect(
LPCRECT   
lpRect) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém as coordenadas do canto superior esquerdo e inferior direito de um retângulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os dois retângulos têm o mesmo superior, esquerda, inferior e direita valores; Caso contrário, 0.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#40](../../atl-mfc-shared/codesnippet/CPP/crect-class_6.cpp)]  
  
##  <a name="a-namecrectheighta-crectheight"></a><a name="crect__height"></a>  CRect::Height  
 Calcula a altura de `CRect` subtraindo o valor superior do valor inferior.  
  
```  
int Height() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O valor resultante pode ser negativo.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#41](../../atl-mfc-shared/codesnippet/CPP/crect-class_7.cpp)]  
  
##  <a name="a-namecrectinflaterecta-crectinflaterect"></a><a name="crect__inflaterect"></a>  CRect::InflateRect  
 `InflateRect` inflar `CRect` movendo suas laterais para fora do seu centro.  
  
```  
 
    void InflateRect(
    int 
    x ,  
    int 
    y) throw();
void InflateRect(
    SIZE 
    size) throw();
void InflateRect(
    LPCRECT 
    lpRect) throw();
void InflateRect(
    int 
    l ,  
    int 
    t ,  
    int 
    r ,  
    int 
    b) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades para aumentar à esquerda e à direita do `CRect`.  
  
 *y*  
 Especifica o número de unidades para aumentar a parte superior e inferior de `CRect`.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) ou [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o número de unidades para aumentar `CRect`. O `cx` valor Especifica o número de unidades para aumentar os lados esquerdo e direito e `cy` valor Especifica o número de unidades para aumentar a parte superior e inferior.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` que especifica o número de unidades para aumentar cada lado.  
  
 *l*  
 Especifica o número de unidades para aumentar o lado esquerdo da `CRect`.  
  
 *t*  
 Especifica o número de unidades para aumentar a parte superior do `CRect`.  
  
 *r*  
 Especifica o número de unidades para aumentar o lado direito da `CRect`.  
  
 *b*  
 Especifica o número de unidades para aumentar a parte inferior da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 Para fazer isso, `InflateRect` subtrai unidades de left e top e adiciona as unidades para a direita e inferior. Os parâmetros de `InflateRect` assinadas valores; aumentar valores positivos `CRect` e valores negativos deflate-lo.  
  
 As primeiras duas sobrecargas inflar dois pares de lados opostos `CRect` para que sua largura total é aumentada em duas vezes *x* (ou `cx`) e sua altura total é aumentada em duas vezes *y* (ou `cy`). As duas sobrecargas aumentar cada lado da `CRect` independentemente dos outros.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#42](../../atl-mfc-shared/codesnippet/CPP/crect-class_8.cpp)]  
  
##  <a name="a-namecrectintersectrecta-crectintersectrect"></a><a name="crect__intersectrect"></a>  CRect::IntersectRect  
 Faz uma `CRect` igual a interseção de dois retângulos existentes.  
  
```  
 
    BOOL IntersectRect(
    LPCRECT 
    lpRect1 ,  
    LPCRECT 
    lpRect2) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect1`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
 `lpRect2`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a interseção não está vazia; 0 se a interseção está vazia.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contido em dois retângulos existentes.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#43](../../atl-mfc-shared/codesnippet/CPP/crect-class_9.cpp)]  
  
##  <a name="a-namecrectisrectemptya-crectisrectempty"></a><a name="crect__isrectempty"></a>  CRect::IsRectEmpty  
 Determina se `CRect` está vazia.  
  
```  
BOOL IsRectEmpty() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect` estiver vazia; 0 se `CRect` não está vazio.  
  
### <a name="remarks"></a>Comentários  
 Um retângulo é vazia se a altura e/ou largura forem 0 ou negativo. É diferente de `IsRectNull`, que determina se todas as coordenadas do retângulo são zero.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#44](../../atl-mfc-shared/codesnippet/CPP/crect-class_10.cpp)]  
  
##  <a name="a-namecrectisrectnulla-crectisrectnull"></a><a name="crect__isrectnull"></a>  CRect::IsRectNull  
 Determina se a parte superior, esquerda, inferior e para a direita os valores de `CRect` são todos iguais a 0.  
  
```  
BOOL IsRectNull() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `CRect`da parte superior, esquerda, inferior e valores corretos são todos iguais a 0; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 É diferente de `IsRectEmpty`, que determina se o retângulo está vazio.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#45](../../atl-mfc-shared/codesnippet/CPP/crect-class_11.cpp)]  
  
##  <a name="a-namecrectmovetoxa-crectmovetox"></a><a name="crect__movetox"></a>  CRect::MoveToX  
 Chame essa função para mover o retângulo para a absoluta coordenada x especificada pelo *x*.  
  
```  
 
void MoveToX(
int   
x) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A absoluta coordenada x para o canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#46](../../atl-mfc-shared/codesnippet/CPP/crect-class_12.cpp)]  
  
##  <a name="a-namecrectmovetoxya-crectmovetoxy"></a><a name="crect__movetoxy"></a>  CRect::MoveToXY  
 Chame essa função para mover o retângulo para a absoluta coordenadas x e y-especificada.  
  
```  
 
    void MoveToXY(
    int 
    x ,  
    int 
    y) throw();
void MoveToXY(
    POINT 
    point) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A absoluta coordenada x para o canto superior esquerdo do retângulo.  
  
 *y*  
 A absoluta coordenada y do canto superior esquerdo do retângulo.  
  
 `point`  
 Um **PONTO** estrutura especificando o absoluto canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#47](../../atl-mfc-shared/codesnippet/CPP/crect-class_13.cpp)]  
  
##  <a name="a-namecrectmovetoya-crectmovetoy"></a><a name="crect__movetoy"></a>  CRect::MoveToY  
 Chame essa função para mover o retângulo para a absoluta coordenada y especificada pelo *y*.  
  
```  
 
void MoveToY(
int   
y) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *y*  
 A absoluta coordenada y do canto superior esquerdo do retângulo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#48](../../atl-mfc-shared/codesnippet/CPP/crect-class_14.cpp)]  
  
##  <a name="a-namecrectnormalizerecta-crectnormalizerect"></a><a name="crect__normalizerect"></a>  CRect::NormalizeRect  
 Normaliza `CRect` para que a altura e a largura são positivos.  
  
```  
void NormalizeRect() throw();
```  
  
### <a name="remarks"></a>Comentários  
 O retângulo é normalizado para posicionar o quarto quadrante, que o Windows normalmente usa para coordenadas. `NormalizeRect` compara os valores superior e inferior e troca se início for maior que a parte inferior. Da mesma forma, ele troca os valores de esquerda e direito, se a esquerda for maior que o direito. Essa função é útil ao lidar com modos diferentes de mapeamento e invertido retângulos.  
  
> [!NOTE]
>  O seguinte `CRect` funções de membro exigem retângulos normalizados para funcionar corretamente: [Altura](#crect__height), [largura](#crect__width), [tamanho](#crect__size), [IsRectEmpty](#crect__isrectempty), [PtInRect](#crect__ptinrect), [EqualRect](#crect__equalrect), [UnionRect](#crect__unionrect), [IntersectRect](#crect__intersectrect), [SubtractRect](#crect__subtractrect), [operador = =](#crect__operator__eq_eq), [operador! =](#crect__operator__neq), [operador &#124;](#crect__operator__or), [operador &#124; =](#crect__operator__or_eq), [operador &](#crect__operator__amp_), e [operador & =](#crect__operator__amp__eq).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#49](../../atl-mfc-shared/codesnippet/CPP/crect-class_15.cpp)]  
  
##  <a name="a-namecrectoffsetrecta-crectoffsetrect"></a><a name="crect__offsetrect"></a>  CRect::OffsetRect  
 Move `CRect` pelos deslocamentos especificados.  
  
```  
 
    void OffsetRect(
    int 
    x ,  
    int 
    y) throw();
void OffsetRect(
    POINT 
    point) throw();
void OffsetRect(
    SIZE 
    size) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a quantidade para mover para a esquerda ou direita. Ele deve ser negativo para mover para a esquerda.  
  
 *y*  
 Especifica a quantidade de mover para cima ou para baixo. Ele deve ser negativo para mover para cima.  
  
 `point`  
 Contém uma [PONTO](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../Topic/CPoint%20Class.md) objeto especificando ambas as dimensões pela qual mover.  
  
 `size`  
 Contém um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto especificando ambas as dimensões pela qual mover.  
  
### <a name="remarks"></a>Comentários  
 Move `CRect`*x* unidades no eixo e *y* unidades no eixo y. O *x* e *y* parâmetros são valores assinados, então `CRect` podem ser movidos para a esquerda ou para a direita e para cima ou para baixo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#50](../../atl-mfc-shared/codesnippet/CPP/crect-class_16.cpp)]  
  
##  <a name="a-namecrectoperatorlpcrecta-crectoperator-lpcrect"></a><a name="crect__operator_lpcrect"></a>  CRect::operator LPCRECT  
 Converte um `CRect` para um [LPCRECT](../Topic/Data%20Types%20\(MFC\).md).  
  
' ' Throw () const de LPCRECT() de operador;
```  
  
### Remarks  
 When you use this function, you don't need the address-of ( **&**) operator. This operator will be automatically used when you pass a `CRect` object to a function that expects an **LPCRECT**.  
  
### Example  
 [!code-cpp[NVC_ATLMFC_Utilities#58](../../atl-mfc-shared/codesnippet/CPP/crect-class_17.cpp)]  
  
##  <a name="crect__operator_lprect"></a>  CRect::operator LPRECT  
 Converts a `CRect` to an [LPRECT](../Topic/Data%20Types%20\(MFC\).md).  
  
```  operator LPRECT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Quando você usa essa função, você não precisa address-of ( **&**) operador. Esse operador será usado automaticamente quando você passa um `CRect` objeto para uma função que espera um `LPRECT`.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::operator LPCRECT](#crect__operator_lpcrect).  
  
##  <a name="a-namecrectoperatoreqa-crectoperator-"></a><a name="crect__operator__eq"></a>  CRect::operator =  
 Atribui *srcRect* para `CRect`.  
  
```  
 
void operator=(
const RECT& 
srcRect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *srcRect*  
 Refere-se a um retângulo de origem. Pode ser um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#59](../../atl-mfc-shared/codesnippet/CPP/crect-class_18.cpp)]  
  
##  <a name="a-namecrectoperatoreqeqa-crectoperator-"></a><a name="crect__operator__eq_eq"></a>  CRect::operator = =  
 Determina se `rect` é igual a `CRect` Comparando as coordenadas dos seus cantos superior esquerdo e inferior direito.  
  
```  
 
BOOL operator==(
const RECT& 
rect) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Refere-se a um retângulo de origem. Pode ser um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se iguais; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#60](../../atl-mfc-shared/codesnippet/CPP/crect-class_19.cpp)]  
  
##  <a name="a-namecrectoperatorneqa-crectoperator-"></a><a name="crect__operator__neq"></a>  CRect::operator! =  
 Determina se `rect` não é igual a `CRect` Comparando as coordenadas dos seus cantos superior esquerdo e inferior direito.  
  
```  
 
BOOL operator!=(
const RECT& 
rect) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Refere-se a um retângulo de origem. Pode ser um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se não iguais; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#61](../../atl-mfc-shared/codesnippet/CPP/crect-class_20.cpp)]  
  
##  <a name="a-namecrectoperatoraddeqa-crectoperator-"></a><a name="crect__operator__add_eq"></a>  + = CRect::operator  
 As primeiras duas sobrecargas mover `CRect` pelos deslocamentos especificados.  
  
```  
 
void operator+=(
POINT   
point) throw();

void operator+=(
SIZE   
size) throw();

void operator+=(
LPCRECT   
lpRect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Um [PONTO](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../Topic/CPoint%20Class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para aumentar cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores forem adicionados a `CRect`.  
  
 O terceiro sobrecarregamento infla `CRect` pelo número de unidades especificado em cada membro do parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#62](../../atl-mfc-shared/codesnippet/CPP/crect-class_21.cpp)]  
  
##  <a name="a-namecrectoperator-eqa-crectoperator--"></a><a name="crect__operator_-_eq"></a>  CRect::operator =  
 As primeiras duas sobrecargas mover `CRect` pelos deslocamentos especificados.  
  
```  
 
void operator-=(
POINT   
point) throw();

void operator-=(
SIZE   
size) throw();

void operator-=(
LPCRECT   
lpRect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Um [PONTO](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../Topic/CPoint%20Class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o número de unidades para mover o retângulo.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado da `CRect`.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) valores são subtraídos do `CRect`.  
  
 O terceiro sobrecarregamento esvaziamento `CRect` pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#crect__deflaterect).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#63](../../atl-mfc-shared/codesnippet/CPP/crect-class_22.cpp)]  
  
##  <a name="a-namecrectoperatorampeqa-crectoperator-amp"></a><a name="crect__operator__amp__eq"></a>  CRect::operator &amp;=  
 Conjuntos de `CRect` igual a interseção de `CRect` e `rect`.  
  
```  
 
void operator&=(
const RECT& 
rect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Contém um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contidos em dois retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::IntersectRect](#crect__intersectrect).  
  
##  <a name="a-namecrectoperatororeqa-crectoperator-124"></a><a name="crect__operator__or_eq"></a>  CRect::operator &#124; =  
 Conjuntos de `CRect` igual a união de `CRect` e `rect`.  
  
```  
 
void operator|=(
const RECT& 
rect) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Contém um `CRect` ou [RECT](RECT%20Structure1.md).  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém dois retângulos de origem.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#64](../../atl-mfc-shared/codesnippet/CPP/crect-class_23.cpp)]  
  
##  <a name="a-namecrectoperatoradda-crectoperator-"></a><a name="crect__operator__add"></a>  CRect::operator +  
 As primeiras duas sobrecargas retornam um `CRect` objeto que é igual a `CRect` substituídos pelos deslocamentos especificados.  
  
```  
 
CRect operator+(
POINT   
point) const throw();

CRect operator+(
LPCRECT   
lpRect) const throw();

CRect operator+(
SIZE   
size) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Um [PONTO](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../Topic/CPoint%20Class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para aumentar cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou aumentando `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são adicionados ao `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual a `CRect` inflado pelo número de unidades especificado em cada membro do parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#65](../../atl-mfc-shared/codesnippet/CPP/crect-class_24.cpp)]  
  
##  <a name="a-namecrectoperator-a-crectoperator--"></a><a name="crect__operator_-"></a>  CRect::operator-  
 As primeiras duas sobrecargas retornam um `CRect` objeto que é igual a `CRect` substituídos pelos deslocamentos especificados.  
  
```  
 
CRect operator-(
POINT   
point) const throw();

CRect operator-(
SIZE   
size) const throw();

CRect operator-(
LPCRECT   
lpRect) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Um [PONTO](../../mfc/reference/point-structure1.md) estrutura ou `CPoint` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `size`  
 Um [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou `CSize` objeto que especifica o número de unidades para mover o valor de retorno.  
  
 `lpRect`  
 Aponta para um [RECT](RECT%20Structure1.md) estrutura ou `CRect` objeto que contém o número de unidades para deflate cada lado do valor de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRect` resultante da movimentação ou deflating `CRect` pelo número de unidades especificadas no parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *x* e *y* (ou `cx` e `cy`) parâmetros são subtraídos do `CRect`da posição.  
  
 A terceira sobrecarga retorna um novo `CRect` que é igual a `CRect` desinflada pelo número de unidades especificado em cada membro do parâmetro. Observe que essa sobrecarga funciona como [DeflateRect](#crect__deflaterect), não [SubtractRect](#crect__subtractrect).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#66](../../atl-mfc-shared/codesnippet/CPP/crect-class_25.cpp)]  
  
##  <a name="a-namecrectoperatorampa-crectoperator-amp"></a><a name="crect__operator__amp_"></a>  CRect::operator &amp;  
 Retorna um `CRect` que é a interseção de `CRect` e *rect2*.  
  
```  
 
CRect operator&(
const RECT& 
rect2) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` que é a interseção de `CRect` e *rect2*.  
  
### <a name="remarks"></a>Comentários  
 A interseção é o retângulo maior contidos em dois retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#67](../../atl-mfc-shared/codesnippet/CPP/crect-class_26.cpp)]  
  
##  <a name="a-namecrectoperatorora-crectoperator-124"></a><a name="crect__operator__or"></a>  CRect::operator &#124;  
 Retorna um `CRect` que é a união de `CRect` e *rect2*.  
  
```  
 
CRect operator|(
const RECT& 
rect2) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 *rect2*  
 Contém um [RECT](RECT%20Structure1.md) ou `CRect`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` que é a união de `CRect` e *rect2*.  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém os dois retângulos.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#68](../../atl-mfc-shared/codesnippet/CPP/crect-class_27.cpp)]  
  
##  <a name="a-namecrectptinrecta-crectptinrect"></a><a name="crect__ptinrect"></a>  CRect::PtInRect  
 Determina se o ponto especificado está em `CRect`.  
  
```  
 
BOOL PtInRect(
POINT   
point) const throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 Contém uma [PONTO](../../mfc/reference/point-structure1.md) estrutura ou [CPoint](../Topic/CPoint%20Class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto está dentro de `CRect`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um ponto está dentro de `CRect` se ele está no lado esquerdo ou superior ou em todos os quatro lados. Um ponto no lado direito ou inferior estiver fora `CRect`.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#51](../../atl-mfc-shared/codesnippet/CPP/crect-class_28.cpp)]  
  
##  <a name="a-namecrectsetrecta-crectsetrect"></a><a name="crect__setrect"></a>  CRect::SetRect  
 Define as dimensões de `CRect` para as coordenadas especificadas.  
  
```  
 
    void SetRect(
    int 
    x1 ,  
    int 
    y1 ,  
    int 
    x2 ,  
    int 
    y2) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo.  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo.  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito.  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#52](../../atl-mfc-shared/codesnippet/CPP/crect-class_29.cpp)]  
  
##  <a name="a-namecrectsetrectemptya-crectsetrectempty"></a><a name="crect__setrectempty"></a>  CRect::SetRectEmpty  
 Torna `CRect` um retângulo nulo definindo todas as coordenadas como zero.  
  
```  
void SetRectEmpty() throw();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#53](../../atl-mfc-shared/codesnippet/CPP/crect-class_30.cpp)]  
  
##  <a name="a-namecrectsizea-crectsize"></a><a name="crect__size"></a>  CRect::Size  
 O `cx` e `cy` membros do valor de retorno contém a altura e largura do `CRect`.  
  
```  
CSize Size() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) que contém o tamanho do objeto `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A altura ou largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#54](../../atl-mfc-shared/codesnippet/CPP/crect-class_31.cpp)]  
  
##  <a name="a-namecrectsubtractrecta-crectsubtractrect"></a><a name="crect__subtractrect"></a>  CRect::SubtractRect  
 Faz com que as dimensões do **CRect** igual a subtração de `lpRectSrc2` de `lpRectSrc1`.  
  
```  
 
    BOOL SubtractRect(
    LPCRECT 
    lpRectSrc1 ,  
    LPCRECT 
    lpRectSrc2) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRectSrc1`  
 Aponta para a [RECT](RECT%20Structure1.md) estrutura ou `CRect` da qual um retângulo é subtraído do objeto.  
  
 `lpRectSrc2`  
 Aponta para a `RECT` estrutura ou `CRect` objeto a ser subtraído do retângulo apontada para o `lpRectSrc1` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A subtração é o menor retângulo que contém todos os pontos de `lpRectScr1` que não estão na interseção de `lpRectScr1` e *lpRectScr2*.  
  
 O retângulo especificado pelo `lpRectSrc1` será alterado se o retângulo especificado por `lpRectSrc2` completamente não se sobreponha o retângulo especificado por *lpRectSrc1* em pelo menos um da x - ou y-direções.  
  
 Por exemplo, se `lpRectSrc1` foram (10,10, 100,100) e `lpRectSrc2` foram (50,50, 150,150), o retângulo apontada por `lpRectSrc1` seria inalterado quando a função é retornada. Se `lpRectSrc1` foram (10,10, 100,100) e `lpRectSrc2` foram (50,10, 150,150), no entanto, o retângulo apontada por `lpRectSrc1` conteria as coordenadas (10,10, 50,100) quando a função é retornada.  
  
 `SubtractRect` não é o mesmo que [operador -](#crect__operator_-) nem [operador-=](#crect__operator_-_eq). Nenhum desses operadores nunca chama `SubtractRect`.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#55](../../atl-mfc-shared/codesnippet/CPP/crect-class_32.cpp)]  
  
##  <a name="a-namecrecttoplefta-crecttopleft"></a><a name="crect__topleft"></a>  CRect::TopLeft  
 As coordenadas são retornadas como uma referência a um [CPoint](../Topic/CPoint%20Class.md) contido no objeto `CRect`.  
  
```  
 
CPoint& TopLeft() throw();

const CPoint& TopLeft() const throw();

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto superior esquerdo do retângulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para obter ou definir o canto superior esquerdo do retângulo. Defina o canto usando essa função no lado esquerdo do operador de atribuição.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CRect::CenterPoint](#crect__centerpoint).  
  
##  <a name="a-namecrectunionrecta-crectunionrect"></a><a name="crect__unionrect"></a>  CRect::UnionRect  
 Faz com que as dimensões de `CRect` igual a união dos retângulos dois fonte.  
  
```  
 
    BOOL UnionRect(
    LPCRECT 
    lpRect1 ,  
    LPCRECT 
    lpRect2) throw();

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect1`  
 Aponta para um [RECT](RECT%20Structure1.md) ou `CRect` que contém um retângulo de origem.  
  
 `lpRect2`  
 Aponta para um `RECT` ou `CRect` que contém um retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a união não está vazia. 0 se a união está vazia.  
  
### <a name="remarks"></a>Comentários  
 A união é o menor retângulo que contém dois retângulos de origem.  
  
 O Windows ignora as dimensões de um retângulo vazio; ou seja, um retângulo que não tenha altura ou tem sem largura.  
  
> [!NOTE]
>  Ambos os retângulos devem ser normalizados ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar os retângulos antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#56](../../atl-mfc-shared/codesnippet/CPP/crect-class_33.cpp)]  
  
##  <a name="a-namecrectwidtha-crectwidth"></a><a name="crect__width"></a>  CRect::Width  
 Calcula a largura do `CRect` subtraindo o valor à esquerda do valor à direita.  
  
```  
int Width() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura do `CRect`.  
  
### <a name="remarks"></a>Comentários  
 A largura pode ser negativa.  
  
> [!NOTE]
>  O retângulo deve ser normalizado ou essa função pode falhar. Você pode chamar [NormalizeRect](#crect__normalizerect) normalizar o retângulo antes de chamar essa função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#57](../../atl-mfc-shared/codesnippet/CPP/crect-class_34.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CPoint](../Topic/CPoint%20Class.md)   
 [Classe CSize](../../atl-mfc-shared/reference/csize-class.md)   
 [RECT](RECT%20Structure1.md)

