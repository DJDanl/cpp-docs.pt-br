---
title: Classe CPen | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPen
- AFXWIN/CPen
- AFXWIN/CPen::CPen
- AFXWIN/CPen::CreatePen
- AFXWIN/CPen::CreatePenIndirect
- AFXWIN/CPen::FromHandle
- AFXWIN/CPen::GetExtLogPen
- AFXWIN/CPen::GetLogPen
dev_langs:
- C++
helpviewer_keywords:
- HPEN
- CPen class
- pens, MFC
ms.assetid: 93175a3a-d46c-4768-be8d-863254f97a5f
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
ms.openlocfilehash: edea12c84a8f39161acbf367360fd86a1ff19998
ms.lasthandoff: 02/25/2017

---
# <a name="cpen-class"></a>Classe CPen
Encapsula uma caneta GDI (interface) de dispositivo de gráficos de Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPen : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPen::CPen](#cpen)|Constrói um objeto `CPen`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPen::CreatePen](#createpen)|Cria uma caneta superficial ou geométrica lógica com o estilo especificado, largura e atributos de pincel e anexa-o para o `CPen` objeto.|  
|[CPen::CreatePenIndirect](#createpenindirect)|Cria uma caneta com o estilo, largura e cor fornecido em uma [LOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd145041) estrutura e anexa-o para o `CPen` objeto.|  
|[CPen::FromHandle](#fromhandle)|Retorna um ponteiro para um `CPen` objeto quando é fornecido um Windows `HPEN`.|  
|[CPen::GetExtLogPen](#getextlogpen)|Obtém um [EXTLOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd162711) estrutura subjacente.|  
|[CPen::GetLogPen](#getlogpen)|Obtém um [LOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd145041) estrutura subjacente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPen::operator HPEN](#operator_hpen)|Retorna o identificador anexado ao `CPen` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como usar o `CPen`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CPen`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cpen"></a>CPen::CPen  
 Constrói um objeto `CPen`.  
  
```  
CPen();

 
CPen(
    int nPenStyle,  
    int nWidth,  
    COLORREF crColor);

 
CPen(
    int nPenStyle,  
    int nWidth,  
    const LOGBRUSH* pLogBrush,  
    int nStyleCount = 0,  
    const DWORD* lpStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPenStyle`  
 Especifica o estilo de caneta. Esse parâmetro na primeira versão do construtor pode ser um dos seguintes valores:  
  
- **PS_SOLID** cria uma caneta sólida.  
  
- **PS_DASH** cria uma caneta tracejada. Válido somente quando a largura da caneta é unidades de 1 ou menos, no dispositivo.  
  
- **PS_DOT** cria uma caneta pontilhada. Válido somente quando a largura da caneta é unidades de 1 ou menos, no dispositivo.  
  
- **PS_DASHDOT** cria uma caneta com traços e pontos alternados. Válido somente quando a largura da caneta é unidades de 1 ou menos, no dispositivo.  
  
- **PS_DASHDOTDOT** cria uma caneta com traços e pontos duplos alternados. Válido somente quando a largura da caneta é unidades de 1 ou menos, no dispositivo.  
  
- **PS_NULL** cria uma caneta nula.  
  
- **PS_INSIDEFRAME** cria uma caneta que desenha uma linha dentro do quadro de formas fechadas produzido pelas funções de saída do Windows GDI que especificam um retângulo (por exemplo, o **elipse**, **retângulo**, `RoundRect`, `Pie`, e `Chord` funções de membro). Quando esse estilo é usado com funções de saída da GDI do Windows que não especificam um retângulo (por exemplo, o `LineTo` função de membro), a área de desenho da caneta não é limitada por um quadro.  
  
 A segunda versão do `CPen` construtor Especifica uma combinação de tipo, estilo, limite final e atributos de junção. Os valores de cada categoria devem ser combinados usando o operador OR bit a bit (|). O tipo de caneta pode ser um dos seguintes valores:  
  
- **PS_GEOMETRIC** cria uma caneta geométrica.  
  
- **PS_COSMETIC** cria uma caneta superficial.  
  
     A segunda versão do `CPen` construtor adiciona os seguintes estilos de caneta para `nPenStyle`:  
  
- **PS_ALTERNATE** cria uma caneta que define todos os outros pixels. (Esse estilo é aplicável somente para canetas superficiais.)  
  
- **PS_USERSTYLE** cria uma caneta que usa uma matriz de estilo fornecida pelo usuário.  
  
     O limite final pode ser um dos seguintes valores:  
  
- **PS_ENDCAP_ROUND** tampas são round.  
  
- **PS_ENDCAP_SQUARE** tampas são quadradas.  
  
- **PS_ENDCAP_FLAT** tampas são simples.  
  
     A junção pode ser um dos seguintes valores:  
  
- **PS_JOIN_BEVEL** junções são chanfradas.  
  
- **PS_JOIN_MITER** junções são mitre quando estão dentro do limite atual definido pelo [SetMiterLimit](http://msdn.microsoft.com/library/windows/desktop/dd145076) função. Se a junção exceder esse limite, ele é chanfrado.  
  
- **PS_JOIN_ROUND** junções são arredondadas.  
  
 `nWidth`  
 Especifica a largura da caneta.  
  
-   Para a primeira versão do construtor, se esse valor for 0, a largura em unidades de dispositivo é sempre 1 pixel, independentemente do modo de mapeamento.  
  
-   Para a segunda versão do construtor, se `nPenStyle` é **PS_GEOMETRIC**, a largura é determinada em unidades lógicas. Se `nPenStyle` é **PS_COSMETIC**, a largura deve ser definida como 1.  
  
 `crColor`  
 Contém uma cor RGB para a caneta.  
  
 `pLogBrush`  
 Aponta para um `LOGBRUSH` estrutura. Se `nPenStyle` é **PS_COSMETIC**, o `lbColor` membro do `LOGBRUSH` estrutura Especifica a cor da caneta e o `lbStyle` membro o `LOGBRUSH` estrutura deve ser definida como **BS_SOLID**. Se `nPenStyle` é **PS_GEOMETRIC**, todos os membros devem ser usados para especificar os atributos de pincel da caneta.  
  
 `nStyleCount`  
 Especifica o comprimento, em unidades de palavras duplas, o `lpStyle` matriz. Esse valor deve ser zero se `nPenStyle` não é **PS_USERSTYLE**.  
  
 `lpStyle`  
 Aponta para uma matriz de valores de palavras duplas. O primeiro valor Especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor Especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser **nulo** se `nPenStyle` não é **PS_USERSTYLE**.  
  
### <a name="remarks"></a>Comentários  
 Se você usar o construtor sem argumentos, você deve inicializar resultante `CPen` o objeto com o `CreatePen`, `CreatePenIndirect`, ou `CreateStockObject` funções de membro.  
  
 Se você usar o construtor que aceita argumentos, nenhuma inicialização adicional é necessária. O construtor com argumentos pode lançar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá êxito.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#99;](../../mfc/codesnippet/cpp/cpen-class_1.cpp)]  
  
##  <a name="createpen"></a>CPen::CreatePen  
 Cria uma caneta superficial ou geométrica lógica com o estilo especificado, largura e atributos de pincel e anexa-o para o `CPen` objeto.  
  
```  
BOOL CreatePen(
    int nPenStyle,  
    int nWidth,  
    COLORREF crColor);

 
BOOL CreatePen(
    int nPenStyle,  
    int nWidth,  
    const LOGBRUSH* pLogBrush,  
    int nStyleCount = 0,  
    const DWORD* lpStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPenStyle`  
 Especifica o estilo de caneta. Para obter uma lista dos valores possíveis, consulte o `nPenStyle` parâmetro o [CPen](#cpen) construtor.  
  
 `nWidth`  
 Especifica a largura da caneta.  
  
-   Para a primeira versão do `CreatePen`, se esse valor for 0, a largura em unidades de dispositivo é sempre 1 pixel, independentemente do modo de mapeamento.  
  
-   Para a segunda versão do `CreatePen`, se `nPenStyle` é **PS_GEOMETRIC**, a largura é determinada em unidades lógicas. Se `nPenStyle` é **PS_COSMETIC**, a largura deve ser definida como 1.  
  
 `crColor`  
 Contém uma cor RGB para a caneta.  
  
 `pLogBrush`  
 Aponta para um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura. Se `nPenStyle` é **PS_COSMETIC**, o **lbColor** membro o `LOGBRUSH` estrutura Especifica a cor da caneta e o `lbStyle` membro do `LOGBRUSH` estrutura deve ser definida como **BS_SOLID**. Se **nPenStyle** é **PS_GEOMETRIC**, todos os membros devem ser usados para especificar os atributos de pincel da caneta.  
  
 `nStyleCount`  
 Especifica o comprimento, em unidades de palavras duplas, o `lpStyle` matriz. Esse valor deve ser zero se `nPenStyle` não é **PS_USERSTYLE**.  
  
 `lpStyle`  
 Aponta para uma matriz de valores de palavras duplas. O primeiro valor Especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor Especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser **nulo** se `nPenStyle` não é **PS_USERSTYLE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito, ou zero se o método falhar.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `CreatePen` inicializa uma caneta com o estilo especificado, largura e cor. A caneta posteriormente pode ser selecionada como a caneta atual para qualquer contexto de dispositivo.  
  
 Canetas que têm uma largura maior que 1 pixel sempre deve ter o **PS_NULL**, **PS_SOLID**, ou **PS_INSIDEFRAME** estilo.  
  
 Se tiver uma caneta de **PS_INSIDEFRAME** estilo e uma cor que não corresponde a uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O **PS_SOLID** estilo da caneta não pode ser usado para criar uma caneta com uma cor pontilhada. O estilo **PS_INSIDEFRAME** é idêntico ao **PS_SOLID** se a largura da caneta é menor ou igual a 1.  
  
 A segunda versão do `CreatePen` inicializa uma caneta superficial ou geométrica lógica que foi especificado de estilo, largura e atributos de pincel. A largura da caneta superficial é sempre 1. a largura da caneta geométrica sempre é especificada em unidades do mundo. Depois que um aplicativo cria uma caneta lógica, ele pode selecionar essa caneta em um contexto de dispositivo chamando o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) função. Depois de seleciona uma caneta em um contexto de dispositivo, ele pode ser usado para desenhar linhas e curvas.  
  
-   Se `nPenStyle` é **PS_COSMETIC** e **PS_USERSTYLE**, as entradas de `lpStyle` matriz especificam os comprimentos dos traços e espaços em unidades de estilo. Uma unidade de estilo é definida pelo dispositivo em que a caneta é usada para desenhar uma linha.  
  
-   Se `nPenStyle` é **PS_GEOMETRIC** e **PS_USERSTYLE**, as entradas de `lpStyle` matriz especificar os comprimentos dos traços e espaços em unidades lógicas.  
  
-   Se `nPenStyle` é **PS_ALTERNATE**, a unidade de estilo é ignorada e todos os outros pixels é definida.  
  
 Quando um aplicativo não exige uma caneta determinada, ele deve chamar o [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) membro de função ou destruir o `CPen` do objeto para o recurso não está mais em uso. Um aplicativo não deve excluir uma caneta quando a caneta é selecionada em um contexto de dispositivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#100;](../../mfc/codesnippet/cpp/cpen-class_2.cpp)]  
  
##  <a name="createpenindirect"></a>CPen::CreatePenIndirect  
 Inicializa uma caneta que tem o estilo, largura e cor fornecido na estrutura apontada por `lpLogPen`.  
  
```  
BOOL CreatePenIndirect(LPLOGPEN lpLogPen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogPen`  
 Aponta para o Windows [LOGPEN](../../mfc/reference/logpen-structure.md) estrutura que contém informações sobre a caneta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Canetas que têm uma largura maior que 1 pixel sempre deve ter o **PS_NULL**, **PS_SOLID**, ou **PS_INSIDEFRAME** estilo.  
  
 Se tiver uma caneta de **PS_INSIDEFRAME** estilo e uma cor que não corresponde a uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O **PS_INSIDEFRAME** estilo é idêntico ao **PS_SOLID** se a largura da caneta é menor ou igual a 1.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#101;](../../mfc/codesnippet/cpp/cpen-class_3.cpp)]  
  
##  <a name="fromhandle"></a>CPen::FromHandle  
 Retorna um ponteiro para um `CPen` objeto recebe um identificador para um objeto de caneta GDI do Windows.  
  
```  
static CPen* PASCAL FromHandle(HPEN hPen);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hPen*  
 `HPEN`lidar com a caneta GDI do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CPen` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CPen` objeto não está anexado ao identificador, um temporário `CPen` objeto é criado e anexado. Esse temporário `CPen` objeto é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, em que ponto gráfico temporário todos os objetos são excluídos. Em outras palavras, o objeto temporário só é válido durante o processamento da mensagem de uma janela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#105;](../../mfc/codesnippet/cpp/cpen-class_4.cpp)]  
  
##  <a name="getextlogpen"></a>CPen::GetExtLogPen  
 Obtém um **EXTLOGPEN** estrutura subjacente.  
  
```  
int GetExtLogPen(EXTLOGPEN* pLogPen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLogPen`  
 Aponta para um [EXTLOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd162711) estrutura que contém informações sobre a caneta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O **EXTLOGPEN** estrutura define o estilo, a largura e o pincel atributos de uma caneta. Por exemplo, chamar `GetExtLogPen` para coincidir com o estilo específico de uma caneta.  
  
 Consulte os seguintes tópicos de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter informações sobre atributos de caneta:  
  
- [GetObject](http://msdn.microsoft.com/library/windows/desktop/dd144904)  
  
- [EXTLOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd162711)  
  
- [LOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd145041)  
  
- [ExtCreatePen](http://msdn.microsoft.com/library/windows/desktop/dd162705)  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra a chamada `GetExtLogPen` para recuperar os atributos da caneta e, em seguida, criar uma caneta superficial, novo com a mesma cor.  
  
 [!code-cpp[NVC_MFCDocView&#102;](../../mfc/codesnippet/cpp/cpen-class_5.cpp)]  
  
##  <a name="getlogpen"></a>CPen::GetLogPen  
 Obtém um `LOGPEN` estrutura subjacente.  
  
```  
int GetLogPen(LOGPEN* pLogPen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLogPen`  
 Aponta para um [LOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd145041) estrutura contém informações sobre a caneta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `LOGPEN` estrutura define o estilo, cor e padrão de uma caneta.  
  
 Por exemplo, chamar `GetLogPen` para coincidir com o estilo específico de caneta.  
  
 Consulte os seguintes tópicos de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter informações sobre atributos de caneta:  
  
- [GetObject](http://msdn.microsoft.com/library/windows/desktop/dd144904)  
  
- [LOGPEN](http://msdn.microsoft.com/library/windows/desktop/dd145041)  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra a chamada `GetLogPen` para recuperar um caractere de caneta e, em seguida, criar uma caneta nova e sólida com a mesma cor.  
  
 [!code-cpp[NVC_MFCDocView&#103;](../../mfc/codesnippet/cpp/cpen-class_6.cpp)]  
  
##  <a name="operator_hpen"></a>CPen::operator HPEN  
 Obtém o identificador Windows GDI anexado do `CPen` objeto.  
  
```  
operator HPEN() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CPen` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Este operador é um operador de conversão, que oferece suporte ao uso direto de um `HPEN` objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#104;](../../mfc/codesnippet/cpp/cpen-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CBrush](../../mfc/reference/cbrush-class.md)

