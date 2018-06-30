---
title: 'TN016: Usando várias heranças do C++ com MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.inheritance
dev_langs:
- C++
helpviewer_keywords:
- TN016
- MI (Multiple Inheritance)
- multiple inheritance, MFC support for
ms.assetid: 4ee27ae1-1410-43a5-b111-b6af9b84535d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 059e239f549f8da79207e5ff6a485643252d6d6b
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37123351"
---
# <a name="tn016-using-c-multiple-inheritance-with-mfc"></a>TN016: usando várias heranças do C++ com MFC

Esta anotação descreve como usar várias heranças (MI) com o Microsoft Foundation Classes. O uso de MI não é necessário com MFC. MI não é usado em todas as classes MFC e não é necessário para gravar uma biblioteca de classe.

Os seguintes subtópicos descrevem como MI afeta o uso de comuns linguagens MFC, bem como abrangendo algumas das restrições de MI. Algumas dessas restrições são restrições gerais do C++. Outros são impostos pela arquitetura MFC.

No final desta nota técnica, você encontrará um aplicativo MFC completo que usa MI.

## <a name="cruntimeclass"></a>CRuntimeClass

A persistência e mecanismos de criação de objeto dinâmico de uso MFC a [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) estrutura de dados para identificar exclusivamente as classes. MFC associa uma destas estruturas com cada classe dinâmico e/ou serializável em seu aplicativo. Essas estruturas são inicializadas quando o aplicativo é iniciado usando um objeto estático especial do tipo `AFX_CLASSINIT`.

A implementação atual de `CRuntimeClass` não oferece suporte a informações de tipo de tempo de execução de MI. Isso não significa que você não pode usar MI em seu aplicativo do MFC. No entanto, você terá determinadas responsabilidades ao trabalhar com objetos que têm mais de uma classe base.

O [CObject::IsKindOf](../mfc/reference/cobject-class.md#iskindof) método não corretamente determinará o tipo de um objeto se ele tem várias classes base. Portanto, você não pode usar [CObject](../mfc/reference/cobject-class.md) como uma classe base virtual e todas as chamadas para `CObject` , como funções de membro [CObject::Serialize](../mfc/reference/cobject-class.md#serialize) e [novoCObject::operator](../mfc/reference/cobject-class.md#operator_new)deve ter o qualificador de escopo para que o C++ pode desambiguar a chamada de função apropriada. Quando um programa usa MI em MFC, a classe que contém o `CObject` classe base deve ser a classe mais à esquerda na lista de classes base.

Uma alternativa é usar o `dynamic_cast` operador. Conversão de um objeto com MI para uma de suas classes base forçará o compilador para usar as funções na classe base fornecido. Para obter mais informações, consulte [operador dynamic_cast](../cpp/dynamic-cast-operator.md).

## <a name="cobject---the-root-of-all-classes"></a>CObject - raiz de todas as Classes

Todas as classes significativas derivam direta ou indiretamente da classe `CObject`. `CObject` does não tem nenhum dado de membro, mas ele tem algumas funcionalidades de padrão. Quando você usa MI, você normalmente herda de duas ou mais `CObject`-classes derivadas. O exemplo a seguir ilustra como uma classe pode herdar de um [CFrameWnd](../mfc/reference/cframewnd-class.md) e um [CObList](../mfc/reference/coblist-class.md):

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    // ...
};
CListWnd myListWnd;
```

Nesse caso `CObject` está incluído duas vezes. Isso significa que você precisa de uma maneira para resolver a ambiguidade qualquer referência a `CObject` métodos ou operadores. O **operador novo** e [operador delete](../mfc/reference/cobject-class.md#operator_delete) são dois operadores ambiguidade devem ser resolvidas. Como outro exemplo, o código a seguir causa um erro em tempo de compilação:

```cpp
myListWnd.Dump(afxDump); // compile time error, CFrameWnd::Dump or CObList::Dump
```

## <a name="reimplementing-cobject-methods"></a>Métodos Reimplementação de CObject

Quando você cria uma nova classe que tenha duas ou mais `CObject` derivadas de classes base, você deve reimplementar a `CObject` métodos que você deseja que outras pessoas usem. Operadores **novo** e **excluir** são obrigatórios e [despejar](../mfc/reference/cobject-class.md#dump) é recomendado. Os reimplements de exemplo a seguir o **novo** e **excluir** operadores e o `Dump` método:

```cpp
class CListWnd : public CFrameWnd, public CObList
{
public:
    void* operator new(size_t nSize)
    {
        return CFrameWnd:: operator new(nSize);
    }
    void operator delete(void* p)
    {
        CFrameWnd:: operator delete(p);
    }
    void Dump(CDumpContent& dc)
    {
        CFrameWnd::Dump(dc);
        CObList::Dump(dc);
    }
    // ...
};
```

## <a name="virtual-inheritance-of-cobject"></a>Herança virtual de CObject

Pode parecer que herdando praticamente `CObject` resolveria o problema de ambiguidade de função, mas que não for o caso. Porque não há nenhum dado de membro em `CObject`, você não precisa de herança virtual para evitar várias cópias de dados de membro de classe base. No primeiro exemplo que foi mostrado anteriormente, o `Dump` método virtual é ainda ambíguo porque é implementado de maneira diferente no `CFrameWnd` e `CObList`. A melhor maneira de remover a ambiguidade é seguir as recomendações apresentadas na seção anterior.

## <a name="cobjectiskindof-and-run-time-typing"></a>CObject::IsKindOf e digitando de tempo de execução

O mecanismo de tempo de execução digitando suportado pelo MFC em `CObject` usa as macros DECLARE_DYNAMIC, IMPLEMENT_DYNAMIC, DECLARE_DYNCREATE, IMPLEMENT_DYNCREATE, DECLARE_SERIAL e IMPLEMENT_SERIAL. Essas macros podem executar uma verificação de tipo de tempo de execução para garantir a segurança downcasts.

Essas macros dar suporte a apenas uma única classe base e funcionarão de forma limitada para classes herdadas várias vezes. A classe base que você especificar em IMPLEMENT_DYNAMIC ou IMPLEMENT_SERIAL deve ser a primeiro (ou mais à esquerda) da classe base. Esse posicionamento permite que você para o tipo de verificação para a classe base mais à esquerda só. O sistema de tipos do tempo de execução saberá nada sobre classes base adicionais. O exemplo a seguir, os sistemas de tempo de execução fará verificação em relação de tipo `CFrameWnd`, mas saber nada sobre `CObList`.

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    DECLARE_DYNAMIC(CListWnd)
    // ...
};
IMPLEMENT_DYNAMIC(CListWnd, CFrameWnd)
```

## <a name="cwnd-and-message-maps"></a>Mapas de mensagem e CWnd

Para o sistema de mapa de mensagem do MFC funcionar corretamente, há dois requisitos adicionais:

- Deve haver apenas um `CWnd`-derivado da classe base.

- O `CWnd`-classe base derivada deve ser a primeiro (ou mais à esquerda) da classe base.

Aqui estão alguns exemplos que não funcionarão:

```cpp
class CTwoWindows : public CFrameWnd, public CEdit
{ /* ... */ }; // error : two copies of CWnd

class CListEdit : public CObList, public CEdit
{ /* ... */ }; // error : CEdit (derived from CWnd) must be first
```

## <a name="a-sample-program-using-mi"></a>Um programa de exemplo usando MI

O exemplo a seguir é um aplicativo autônomo que consiste em uma classe derivada de `CFrameWnd` e [CWinApp](../mfc/reference/cwinapp-class.md). Não recomendamos que você estrutura uma aplicação dessa maneira, mas isso é um exemplo de aplicativo MFC menor que tem uma classe.

```cpp
#include <afxwin.h>

class CHelloAppAndFrame : public CFrameWnd, public CWinApp
{
public:
    CHelloAppAndFrame() {}

    // Necessary because of MI disambiguity
    void* operator new(size_t nSize)
        { return CFrameWnd::operator new(nSize); }
    void operator delete(void* p)
        { CFrameWnd::operator delete(p); }

    // Implementation
    // CWinApp overrides
    virtual BOOL InitInstance();
    // CFrameWnd overrides
    virtual void PostNcDestroy();
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CHelloAppAndFrame, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

// because the frame window is not allocated on the heap, we must
// override PostNCDestroy not to delete the frame object
void CHelloAppAndFrame::PostNcDestroy()
{
    // do nothing (do not call base class)
}

void CHelloAppAndFrame::OnPaint()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(rect);

    CString s = "Hello, Windows!";
    dc.SetTextAlign(TA_BASELINE | TA_CENTER);
    dc.SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
    dc.SetBkMode(TRANSPARENT);
    dc.TextOut(rect.right / 2, rect.bottom / 2, s);
}

// Application initialization
BOOL CHelloAppAndFrame::InitInstance()
{
    // first create the main frame
    if (!CFrameWnd::Create(NULL, "Multiple Inheritance Sample",
        WS_OVERLAPPEDWINDOW, rectDefault))
        return FALSE;

    // the application object is also a frame window
    m_pMainWnd = this;
    ShowWindow(m_nCmdShow);
    return TRUE;
}

CHelloAppAndFrame theHelloAppAndFrame;
```

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
