---
title: "TN016: usando v&#225;rias heran&#231;as do C++ com MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.inheritance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MI (Várias Heranças)"
  - "várias heranças, suporte do MFC para"
  - "TN016"
ms.assetid: 4ee27ae1-1410-43a5-b111-b6af9b84535d
caps.latest.revision: 22
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN016: usando v&#225;rias heran&#231;as do C++ com MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve como usar a herança múltipla \(MI\) com as classes do Microsoft.  O uso de MI não é obrigatório com MFC.  MI não é usado em nenhuma MFC classes e não é necessário gravar uma biblioteca da classe.  
  
 As seguintes subtópicos descrevem como MI afeta o uso de CLR \(MFC bem como abrange algumas limitações de MI.  Algumas dessas limitações são restrições gerais C\+\+.  Outro são impostas pela arquitetura de MFC.  
  
 No final desta técnica observação você encontrará um aplicativo completo MFC que usa MI.  
  
## CRuntimeClass  
 Os mecanismos de criação de persistência e do objeto dinâmico MFC usam a estrutura de dados de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) para identificar classes.  O MFC associa uma dessas estruturas com cada classe dinâmico e\/ou serializável em seu aplicativo.  Essas estruturas são inicializadas quando o aplicativo é iniciado usando um objeto de tipo estático especial `AFX_CLASSINIT`.  
  
 A implementação atual de `CRuntimeClass` não da suporte a informações de tipo de tempo de execução de MI.  Isso não significa que você não pode usar MI em seu aplicativo MFC.  No entanto, você terá determinadas responsabilidades quando você trabalha com objetos que têm mais de uma classe base.  
  
 O método de [CObject::IsKindOf](../Topic/CObject::IsKindOf.md) não corretamente determinará o tipo de um objeto se tiver várias classes base.  Consequentemente, você não pode usar [CObject](../Topic/CObject%20Class.md) como uma classe base e virtual, todas as chamadas a funções de membro de `CObject` como [CObject::Serialize](../Topic/CObject::Serialize.md) e o [CObject::operator novo](../Topic/CObject::operator%20new.md) devem ter qualificadores do escopo de forma que possa resolver a ambiguidade C\+\+ a chamada de função apropriada.  Quando um programa usa MI em MFC, a classe que contém a classe base de `CObject` precisa ser a classe mais à esquerda na lista de classes base.  
  
 Uma alternativa é usar o operador de `dynamic_cast` .  Convertendo um objeto com MI em uma de suas classes base forçará o compilador para usar as funções fornecidas na classe base.  Para obter mais informações, consulte [Operador dynamic\_cast](../cpp/dynamic-cast-operator.md).  
  
## CObject \- a raiz de todas as classes  
 Todas as classes significativas derivam direta ou indiretamente da classe `CObject`.  `CObject` não tem nenhum dado de membro, mas tem alguma funcionalidade padrão.  Quando você usa MI, você normalmente herda de duas ou mais `CObject`\- classes derivadas.  O exemplo a seguir ilustra como uma classe pode herdar de [CFrameWnd](../mfc/reference/cframewnd-class.md) e de [CObList](../mfc/reference/coblist-class.md):  
  
```  
class CListWnd : public CFrameWnd, public CObList  
{  
 ...  
};  
CListWnd myListWnd;  
```  
  
 Nesse caso `CObject` é duas vezes incluídas.  Isso significa que você precisa de uma maneira de resolver a ambiguidade qualquer referência aos métodos ou os operadores de `CObject` .  `operator new` e [a exclusão do operador](../Topic/CObject::operator%20delete.md) são dois operadores que devem ser resolvida.  Como outro exemplo, o seguinte código gerencie um erro em tempo de compilação:  
  
```  
myListWnd.Dump(afxDump);  
    // compile time error, CFrameWnd::Dump or CObList::Dump ?  
```  
  
## Métodos de Reimplementing CObject  
 Quando você cria uma nova classe que tem dois ou mais classes base `CObject` derivadas, você deve reimplementar os métodos de `CObject` que você deseja outras pessoas para usar.  Os operadores `new` e `delete` são obrigatórios e [Despejo](../Topic/CObject::Dump.md) é recomendado.  Os seguintes reimplements de exemplo os operadores de `new` e de `delete` e o método de `Dump` :  
  
```  
class CListWnd : public CFrameWnd, public CObList  
{  
public:  
    void* operator new(size_t nSize)  
        { return CFrameWnd::operator new(nSize); }  
    void operator delete(void* p)  
        { CFrameWnd::operator delete(p); }  
  
    void Dump(CDumpContent& dc)  
        { CFrameWnd::Dump(dc);  
          CObList::Dump(dc); }  
     ...  
};  
```  
  
## Herança virtual de CObject  
 Pode parecer que a inclusão de herdar `CObject` resolverá o problema de ambiguidade da função, mas isso não é o caso.  Porque não há dados de membro em `CObject`, você não precisa da herança virtual de evitar várias cópias de dados de um membro da classe base.  No primeiro exemplo que foi mostrado anteriormente, o método virtual de `Dump` ainda é ambíguo porque é implementado diferentemente em `CFrameWnd` e em `CObList`.  A melhor maneira de remover a ambiguidade é seguir as recomendações apresentadas na seção anterior.  
  
## CObject::IsKindOf e digite de tempo de execução  
 O tempo de execução que digita o mecanismo MFC suporte em `CObject` usar macros `DECLARE_DYNAMIC`, `IMPLEMENT_DYNAMIC`, `DECLARE_DYNCREATE`, `IMPLEMENT_DYNCREATE`, `DECLARE_SERIAL` e `IMPLEMENT_SERIAL`.  Esses macros podem executar uma verificação de tipo em tempo de execução para garantir entradas de aérea seguras.  
  
 Esses macros só dão suporte a uma única classe base e funcionarão de uma maneira limitada para multiplicá\-lo classes herdadas.  A classe base que você especifica em `IMPLEMENT_DYNAMIC` ou `IMPLEMENT_SERIAL` deve ser a primeira \(ou\) classe base da extrema esquerda.  Esta colocação permite fazer a verificação de tipo para a classe base da extrema esquerda somente.  O sistema de tipos de tempo de execução não saberá nada sobre classes base adicionais.  No exemplo a seguir, os sistemas de tempo de execução fará a verificação de tipo em `CFrameWnd`, mas não conhecerão nada sobre `CObList`.  
  
```  
class CListWnd : public CFrameWnd, public CObList  
{  
    DECLARE_DYNAMIC(CListWnd)  
    ...  
};  
IMPLEMENT_DYNAMIC(CListWnd, CFrameWnd)  
```  
  
## CWnd e mapas da mensagem  
 Para que o sistema da mensagem MFC funcione corretamente, há dois requisitos adicionais:  
  
-   Deve haver apenas um `CWnd`\- classe base derivada.  
  
-   `CWnd`\- a classe base derivada deveria ser a primeira \(ou\) classe base da extrema esquerda.  
  
 Veja alguns exemplos que não funcionarão:  
  
```  
class CTwoWindows : public CFrameWnd, public CEdit  
    { ... };  
        // error : two copies of CWnd  
  
class CListEdit : public CObList, public CEdit  
    { ... };  
        // error : CEdit (derived from CWnd) must be first  
```  
  
## Um programa de exemplo usando MI  
 O seguinte exemplo é um aplicativo autônomo que consiste em uma classe derivada de `CFrameWnd` e de [CWinApp](../mfc/reference/cwinapp-class.md).  Não recomendamos que você estrutura um aplicativo assim, mas este é um exemplo de aplicativo do menor MFC que tem uma classe.  
  
```  
#include <afxwin.h>  
  
class CHelloAppAndFrame : public CFrameWnd, public CWinApp  
{   
public:  
    CHelloAppAndFrame()  
        { }  
  
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
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)