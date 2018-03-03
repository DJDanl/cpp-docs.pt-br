---
title: Exportando e importando usando AFX_EXT_CLASS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- afx_ext_class
dev_langs:
- C++
helpviewer_keywords:
- AFX_EXT_CLASS macro
- exporting classes [C++]
- importing DLLs [C++]
- extension DLLs [C++], exporting classes
- executable files [C++], importing classes
- exporting DLLs [C++], AFX_EXT_CLASS macro
ms.assetid: 6b72cb2b-e92e-4ecd-bcab-c335e1d1cfde
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fb47703b7cd4ef2d0493016c120db0b7d845a71f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exporting-and-importing-using-afxextclass"></a>Exportando e importando usando AFX_EXT_CLASS  
  
[DLLs de extensão do MFC](../build/extension-dlls-overview.md) use a macro **AFX_EXT_CLASS** exportar classes; os executáveis que o link para a DLL de extensão do MFC usam a macro para importar classes. Com o **AFX_EXT_CLASS** macro, os mesmos arquivos de cabeçalho que são usados para criar a DLL pode ser usado com os executáveis que o link para a DLL de extensão do MFC.  
  
 No arquivo de cabeçalho para a DLL, adicione o **AFX_EXT_CLASS** palavra-chave para a declaração da classe da seguinte maneira:  
  
```cpp  
class AFX_EXT_CLASS CMyClass : public CDocument  
{  
// <body of class>  
};  
```  
  
Essa macro é definida por MFC como `__declspec(dllexport)` quando os símbolos de pré-processamento `_AFXDLL` e `_AFXEXT` são definidos. Mas a macro é definida como `__declspec(dllimport)` quando `_AFXDLL` é definido e `_AFXEXT` não está definido. Quando definido, o símbolo do pré-processador `_AFXDLL` indica que a versão compartilhada do MFC está sendo usada por um executável de destino (uma DLL ou um aplicativo). Quando ambos `_AFXDLL` e `_AFXEXT` são definidas, isso indica que o executável de destino é uma DLL de extensão do MFC.  
  
Porque `AFX_EXT_CLASS` é definido como `__declspec(dllexport)` durante a exportação de uma DLL de extensão do MFC, você pode exportar classes inteiras sem colocar os nomes decorados para todos os símbolos dessa classe no arquivo. def.  
  
Embora você possa impedir a criação de um arquivo. def e todos os nomes decorados para a classe com esse método, criar um arquivo. def é mais eficiente porque os nomes podem ser exportados por ordinal. Para usar o método de arquivo. def de exportação, coloque o seguinte código no início e no final do arquivo de cabeçalho:  
  
```cpp  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
> [!CAUTION]
>  Tenha cuidado ao exportar funções embutidas, pois eles podem criar a possibilidade de conflitos de versão. Uma função embutida obtém expandida em código do aplicativo; Portanto, se você posteriormente reescrever a função, ele não é atualizado, a menos que o aplicativo em si é recompilado. Normalmente, as funções DLL podem ser atualizadas sem recompilar os aplicativos que utilizam.  
  
## <a name="exporting-individual-members-in-a-class"></a>Exportar membros individuais em uma classe  
  
Às vezes, você talvez queira exportar membros individuais da sua classe. Por exemplo, se você estiver exportando um `CDialog`-derivado da classe, você só precisa exportar o construtor e o `DoModal` chamar. Você pode usar `AFX_EXT_CLASS` nos membros individuais, você precisa exportar.  
  
Por exemplo:  
  
```cpp  
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
  
Porque você não estiver exportando todos os membros da classe, você pode encontrar um problema adicional por causa da forma que funcionam de macros MFC. Na verdade, várias das macros do auxiliar do MFC declaram ou definem membros de dados. Portanto, esses membros de dados também devem ser exportados por sua DLL.  
  
Por exemplo, o `DECLARE_DYNAMIC` macro é definida como a seguir ao criar uma DLL de extensão do MFC:  
  
```cpp  
#define DECLARE_DYNAMIC(class_name) \  
protected: \  
   static CRuntimeClass* PASCAL _GetBaseClass(); \  
public: \  
   static AFX_DATA CRuntimeClass class##class_name; \  
   virtual CRuntimeClass* GetRuntimeClass() const; \  
```  
  
A linha que começa com estática `AFX_DATA` está declarando um objeto estático dentro de sua classe. Para exportar esta classe corretamente e acessar as informações de tempo de execução de um executável do cliente, você deve exportar esse objeto estático. Porque o objeto estático é declarado com o modificador `AFX_DATA`, você precisa definir `AFX_DATA` ser `__declspec(dllexport)` ao criar a DLL e defini-lo como `__declspec(dllimport)` ao criar o executável do cliente. Porque `AFX_EXT_CLASS` já está definido dessa maneira, você só precisa redefinir `AFX_DATA` para ser o mesmo que `AFX_EXT_CLASS` em torno de sua definição de classe.  
  
Por exemplo:  
  
```cpp  
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
  
Como o MFC sempre usa o `AFX_DATA` símbolo em itens de dados define em suas macros, isso funciona técnica para todos esses cenários. Por exemplo, ele funciona para `DECLARE_MESSAGE_MAP`.  
  
> [!NOTE]
>  Se você estiver exportando a classe inteira em vez de membros selecionados da classe, membros de dados estáticos são exportados automaticamente.  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções C para uso em executáveis C ou linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)