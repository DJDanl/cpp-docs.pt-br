---
title: Classe CDumpContext | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDumpContext
dev_langs:
- C++
helpviewer_keywords:
- CDumpContext class
- AfxDump object
- diagnostics, diagnostic classes
- diagnostic classes
- diagnosis, diagnostic classes
ms.assetid: 98c52b2d-14b5-48ed-b423-479a4d1c60fa
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
ms.openlocfilehash: 40d833772735e1079647f8f3205fb8db736843fd
ms.lasthandoff: 02/25/2017

---
# <a name="cdumpcontext-class"></a>Classe CDumpContext
Saída de diagnóstico de suporte orientado por fluxo na forma de texto legível.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDumpContext  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDumpContext::CDumpContext](#cdumpcontext)|Constrói um objeto `CDumpContext`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDumpContext::DumpAsHex](#dumpashex)|Despeja o item indicado em formato hexadecimal.|  
|[CDumpContext::Flush](#flush)|Libera todos os dados no buffer de contexto de despejo.|  
|[CDumpContext::GetDepth](#getdepth)|Obtém um valor de inteiro correspondente a profundidade do despejo.|  
|[CDumpContext::HexDump](#hexdump)|Despejos de bytes contidos em uma matriz no formato hexadecimal.|  
|[CDumpContext::SetDepth](#setdepth)|Define a profundidade do despejo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDumpContext::operator&lt;&lt;](#operator_lt_lt)|Insere variáveis e objetos no contexto de despejo.|  
  
## <a name="remarks"></a>Comentários  
 `CDumpContext`não tem uma classe base.  
  
 Você pode usar [afxDump](http://msdn.microsoft.com/library/4b3cfa3f-fb75-456a-9d99-a5601acbcb11), um declaradas previamente `CDumpContext` objeto, para a maioria de seu despejo. O `afxDump` objeto está disponível somente na versão de depuração da Microsoft Foundation Class Library.  
  
 Vários da memória [serviços de diagnóstico](../../mfc/reference/diagnostic-services.md) usar `afxDump` para sua saída.  
  
 No ambiente do Windows, a saída do predefinida `afxDump` objeto, conceitualmente semelhante do `cerr` de fluxo, será roteado para o depurador por meio da função do Windows **OutputDebugString**.  
  
 O `CDumpContext` classe tem uma inserção sobrecarregada ( ** << **) operador para `CObject` ponteiros que despeja os dados do objeto. Se você precisar de um formato personalizado de despejo para um objeto derivado, substituir [CObject::Dump](../../mfc/reference/cobject-class.md#dump). A maioria das Microsoft Foundation classes implementam um substituída `Dump` função de membro.  
  
 Classes que não são derivadas de `CObject`, como `CString`, `CTime`, e `CTimeSpan`, têm seus próprios sobrecarregado `CDumpContext` operadores de inserção, como estruturas são usadas com frequência, como **CFileStatus**, `CPoint`, e `CRect`.  
  
 Se você usar o [IMPLEMENT_DYNAMIC](../../mfc/reference/run-time-object-model-services.md#implement_dynamic) ou [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macro na implementação de sua classe, em seguida, `CObject::Dump` imprimirá o nome do seu `CObject`-classe derivada. Caso contrário, ele imprimirá `CObject`.  
  
 O `CDumpContext` classe está disponível com as versões de depuração e a versão da biblioteca, mas o `Dump` função de membro é definida apenas na versão de depuração. Use **Debug #ifdef**  /  `#endif` instruções colchete seu código de diagnóstico, incluindo seu personalizado `Dump` funções de membro.  
  
 Antes de criar seu próprio `CDumpContext` do objeto, você deve criar um `CFile` objeto que serve como o destino de despejo.  
  
 Para obter mais informações sobre `CDumpContext`, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  
  
 **#define Debug**  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CDumpContext`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namecdumpcontexta--cdumpcontextcdumpcontext"></a><a name="cdumpcontext"></a>CDumpContext::CDumpContext  
 Constrói um objeto da classe `CDumpContext`.  
  
```  
CDumpContext(CFile* pFile = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFile`  
 Um ponteiro para o `CFile` objeto que é o destino de despejo.  
  
### <a name="remarks"></a>Comentários  
 O `afxDump` objeto é criado automaticamente.  
  
 Não gravar subjacente `CFile` enquanto o contexto de despejo estiver ativo; caso contrário, você irá interferir com o despejo. No ambiente do Windows, a saída é roteada para o depurador por meio da função Windows **OutputDebugString**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#12;](../../mfc/codesnippet/cpp/cdumpcontext-class_1.cpp)]  
  
##  <a name="a-namedumpashexa--cdumpcontextdumpashex"></a><a name="dumpashex"></a>CDumpContext::DumpAsHex  
 O tipo especificado formatado como números hexadecimais de despejos de memória.  
  
```  
CDumpContext& DumpAsHex(BYTE b);  
CDumpContext& DumpAsHex(DWORD dw);  
CDumpContext& DumpAsHex(int n);  
CDumpContext& DumpAsHex(LONG l);  
CDumpContext& DumpAsHex(LONGLONG n);  
CDumpContext& DumpAsHex(UINT u);  
CDumpContext& DumpAsHex(ULONGLONG n);  
CDumpContext& DumpAsHex(WORD w);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um objeto `CDumpContext`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para despejar o item do tipo especificado como um número hexadecimal. Para uma matriz de despejo, chame [CDumpContext::HexDump](#hexdump).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&13;](../../mfc/codesnippet/cpp/cdumpcontext-class_2.cpp)]  
  
##  <a name="a-nameflusha--cdumpcontextflush"></a><a name="flush"></a>CDumpContext::Flush  
 Força todos os dados restantes nos buffers a serem gravados no arquivo anexado ao contexto de despejo.  
  
```  
void Flush();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#14;](../../mfc/codesnippet/cpp/cdumpcontext-class_3.cpp)]  
  
##  <a name="a-namegetdeptha--cdumpcontextgetdepth"></a><a name="getdepth"></a>CDumpContext::GetDepth  
 Determina se um despejo detalhado ou superficial está no processo.  
  
```  
int GetDepth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A profundidade do despejo conforme definido pela `SetDepth`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [SetDepth](#setdepth).  
  
##  <a name="a-namehexdumpa--cdumpcontexthexdump"></a><a name="hexdump"></a>CDumpContext::HexDump  
 Uma matriz de bytes formatados como números hexadecimais de despejos de memória.  
  
```  
void HexDump(
    LPCTSTR lpszLine,  
    BYTE* pby,  
    int nBytes,  
    int nWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszLine*  
 Uma cadeia de caracteres de saída no início de uma nova linha.  
  
 *pby*  
 Um ponteiro para um buffer que contém os bytes de despejo.  
  
 `nBytes`  
 O número de bytes para despejar.  
  
 `nWidth`  
 Número máximo de bytes despejados por linha (não a largura da linha de saída).  
  
### <a name="remarks"></a>Comentários  
 Para um tipo de item único e específico como um número hexadecimal de despejo, chame [CDumpContext::DumpAsHex](#dumpashex).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&#15;](../../mfc/codesnippet/cpp/cdumpcontext-class_4.cpp)]  
  
##  <a name="a-nameoperatorltlta--cdumpcontextoperator-ltlt"></a><a name="operator_lt_lt"></a>CDumpContext::operator&lt;&lt;  
 Gera os dados especificados para o contexto de despejo.  
  
```  
CDumpContext& operator<<(const CObject* pOb);  
CDumpContext& operator<<(const CObject& ob);  
CDumpContext& operator<<(LPCTSTR lpsz);  
CDumpContext& operator<<(const void* lp);  
CDumpContext& operator<<(BYTE by);  
CDumpContext& operator<<(WORD w);  
CDumpContext& operator<<(DWORD dw);  
CDumpContext& operator<<(int n);  
CDumpContext& operator<<(double d);  
CDumpContext& operator<<(float f);  
CDumpContext& operator<<(LONG l);  
CDumpContext& operator<<(UINT u);  
CDumpContext& operator<<(LPCWSTR lpsz);  
CDumpContext& operator<<(LPCSTR lpsz);  
CDumpContext& operator<<(LONGLONG n);  
CDumpContext& operator<<(ULONGLONG n);  
CDumpContext& operator<<(HWND h);  
CDumpContext& operator<<(HDC h);  
CDumpContext& operator<<(HMENU h);  
CDumpContext& operator<<(HACCEL h);  
CDumpContext& operator<<(HFONT h);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CDumpContext` referência. Usando o valor de retorno, você pode escrever várias inserções em uma única linha de código-fonte.  
  
### <a name="remarks"></a>Comentários  
 O operador de inserção é sobrecarregado para `CObject` ponteiros, bem como para tipos primitivos mais. Um ponteiro para caracteres resulta em um despejo de conteúdo da cadeia de caracteres. um ponteiro para `void` resulta em um despejo hexadecimal de apenas o endereço. A **LONGLONG** resulta em um despejo de um inteiro assinado de 64 bits; A **ULONGLONG** resulta em um despejo de um inteiro não assinado de 64 bits.  
  
 Se você usar o `IMPLEMENT_DYNAMIC` ou `IMPLEMENT_SERIAL` macro na implementação de sua classe, em seguida, o operador de inserção, por meio de `CObject::Dump`, imprimirá o nome do seu `CObject`-classe derivada. Caso contrário, ele imprimirá `CObject`. Se você substituir o `Dump` função de classe, você pode fornecer uma saída mais significativa do conteúdo do objeto, em vez de um despejo hexadecimal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cdumpcontext-class_5.cpp)]  
  
##  <a name="a-namesetdeptha--cdumpcontextsetdepth"></a><a name="setdepth"></a>CDumpContext::SetDepth  
 Define a profundidade de despejo.  
  
```  
void SetDepth(int nNewDepth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nNewDepth*  
 O novo valor de profundidade.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver descartando um tipo primitivo ou simples `CObject` que contém não ponteiros para outros objetos, um valor de 0 é suficiente. Um valor maior que 0 especifica um despejo de profundidade em que todos os objetos são despejados recursivamente. Por exemplo, um despejo de profundidade de uma coleção despejará todos os elementos da coleção. Você pode usar outros valores específicos de profundidade em suas classes derivadas.  
  
> [!NOTE]
>  Referências circulares não são detectadas nos despejos de profundidade e podem resultar em loops infinitos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities n º&16;](../../mfc/codesnippet/cpp/cdumpcontext-class_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

