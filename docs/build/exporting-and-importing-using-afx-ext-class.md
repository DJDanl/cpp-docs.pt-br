---
title: "Exportando e importando usando AFX_EXT_CLASS | Microsoft Docs"
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
  - "afx_ext_class"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro AFX_EXT_CLASS"
  - "arquivos executáveis [C++], importando classes"
  - "exportando classes [C++]"
  - "exportando DLLs [C++], Macro AFX_EXT_CLASS"
  - "DLLs de extensão [C++], exportando classes"
  - "importando DLLs [C++]"
ms.assetid: 6b72cb2b-e92e-4ecd-bcab-c335e1d1cfde
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando e importando usando AFX_EXT_CLASS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

uso de[A DLL da extensão](../build/extension-dlls-overview.md) a macro **AFX\_EXT\_CLASS** exportar classes; os executáveis que vinculam ao uso da DLL de extensão a macro importar classes.  Com a macro de **AFX\_EXT\_CLASS** , os mesmos arquivos de cabeçalho que são usados para criar a DLL de extensão podem ser usados com os executáveis que vinculam a DLL.  
  
 No arquivo de cabeçalho para o DLL, adicione a palavra\-chave de **AFX\_EXT\_CLASS** à declaração da sua classe como segue:  
  
```  
class AFX_EXT_CLASS CMyClass : public CDocument  
{  
// <body of class>  
};  
```  
  
 Esta macro é definido por MFC como **\_\_declspec\(dllexport\)** quando os símbolos **\_AFXDLL** e `_AFXEXT` de pré\-processador são definidos.  Mas a macro é definido como **\_\_declspec\(dllimport\)** quando **\_AFXDLL** é definido e `_AFXEXT` não será definido.  Quando definido, o símbolo **\_AFXDLL** de pré\-processador indica que a versão compartilhada MFC está sendo usada pelo executável de destino \(DLL\) ou um aplicativo.  Quando **\_AFXDLL** e `_AFXEXT` são definidos, isso indica que o executável de destino é uma DLL da extensão.  
  
 Como **AFX\_EXT\_CLASS** é definido como **\_\_declspec\(dllexport\)** ao exportar de uma DLL da extensão, você pode exportar classes inteiras sem colocar os nomes decorados para todos os símbolos de aquela classe no arquivo .def.  Este método é usado por exemplo [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90)MFC.  
  
 Embora você possa evitar criar um arquivo .def e todos os nomes decorados da classe com esse método, criar um arquivo .def é mais eficiente porque os nomes podem ser exportados por ordinal.  Para usar o método do arquivo .def de exportar, coloque o código a seguir no início e o término do arquivo de cabeçalho:  
  
```  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
> [!CAUTION]
>  Tenha cuidado ao exportar funções embutidas, porque podem criar a possibilidade de conflitos de versão.  Uma função embutida obtém expandido no código do aplicativo; em virtude disso, se você uma recriação posterior a função, ele não será atualizado a menos que o próprio aplicativo é recompilado.  Normalmente, as funções de DLL podem ser atualizadas sem recriar os aplicativos que os utilizam.  
  
## Exportando membros individuais em uma classe  
 Às vezes talvez você queira exportar membros individuais da classe.  Por exemplo, se você estiver exportando `CDialog`\- classe derivada, você pode apenas precisar exportar o construtor e a chamada de `DoModal` .  Você pode usar **AFX\_EXT\_CLASS** nos membros individuais que você precisa exportar.  
  
 Por exemplo:  
  
```  
class CExampleDialog : public CDialog  
{  
public:  
   AFX_EXT_CLASS CExampleDialog();  
   AFX_EXT_CLASS int DoModal();  
   ...  
   // rest of class definition  
   ...  
};  
```  
  
 Como você já não estiver exportando todos os membros de classe, você pode executar em um problema adicional devido à maneira como macros de MFC funcionam.  Vários macros de auxiliar MFC realmente declaram ou define os membros de dados.  Consequentemente, esses membros de dados também devem ser exportado do DLL.  
  
 Por exemplo, a macro de `DECLARE_DYNAMIC` é definido da seguinte maneira para criar uma DLL da extensão:  
  
```  
#define DECLARE_DYNAMIC(class_name) \  
protected: \  
   static CRuntimeClass* PASCAL _GetBaseClass(); \  
public: \  
   static AFX_DATA CRuntimeClass class##class_name; \  
   virtual CRuntimeClass* GetRuntimeClass() const; \  
```  
  
 A linha que começa com `AFX_DATA` estático é declarando um objeto estática dentro da classe.  Para exportar corretamente essa classe e acessar informações de tempo de execução de um executável do cliente, você deverá exportar esse objeto estático.  Como o objeto estático é declarado com o modificador `AFX_DATA`, você só precisa definir `AFX_DATA` para ser **\_\_declspec\(dllexport\)** ao criar seu DLL e define\-o como **\_\_declspec\(dllimport\)** durante a criação do executável do cliente.  Como **AFX\_EXT\_CLASS** já está definido dessa forma, você precisa apenas de redefinir `AFX_DATA` para ser o mesmo que **AFX\_EXT\_CLASS** em torno da definição da classe.  
  
 Por exemplo:  
  
```  
#undef  AFX_DATA  
#define AFX_DATA AFX_EXT_CLASS  
  
class CExampleView : public CView  
{  
   DECLARE_DYNAMIC()  
   // ... class definition ...  
};  
  
#undef  AFX_DATA  
#define AFX_DATA  
```  
  
 Como o MFC sempre usa o símbolo de `AFX_DATA` em itens de dados que define dentro de seus macros, trabalho dessa técnica para todos esses cenários.  Por exemplo, funciona para `DECLARE_MESSAGE_MAP`.  
  
> [!NOTE]
>  Se você estiver exportando a classe inteira em vez de membros selecionados da classe, os membros de dados estáticos são exportados automaticamente.  
  
### O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
### Que você deseja saber mais?  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)