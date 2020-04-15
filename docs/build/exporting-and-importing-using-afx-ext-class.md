---
title: Exportando e importando usando AFX_EXT_CLASS
ms.date: 11/04/2016
f1_keywords:
- afx_ext_class
helpviewer_keywords:
- AFX_EXT_CLASS macro
- exporting classes [C++]
- importing DLLs [C++]
- extension DLLs [C++], exporting classes
- executable files [C++], importing classes
- exporting DLLs [C++], AFX_EXT_CLASS macro
ms.assetid: 6b72cb2b-e92e-4ecd-bcab-c335e1d1cfde
ms.openlocfilehash: 95c72f8251a8a59833483eb948709c80a69d03d7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328603"
---
# <a name="exporting-and-importing-using-afx_ext_class"></a>Exportando e importando usando AFX_EXT_CLASS

[As DLLs de extensão MFC](extension-dlls-overview.md) usam o **AFX_EXT_CLASS** macro para exportar classes; os executáveis que se ligam à extensão MFC DLL usam a macro para importar classes. Com a **macro AFX_EXT_CLASS,** os mesmos arquivos de cabeçalho que são usados para construir o DLL de extensão MFC podem ser usados com os executáveis que se conectam à DLL.

No arquivo de cabeçalho da sua DLL, adicione a **palavra-chave AFX_EXT_CLASS** à declaração da sua classe da seguinte forma:

```cpp
class AFX_EXT_CLASS CMyClass : public CDocument
{
// <body of class>
};
```

Esta macro é definida `__declspec(dllexport)` pelo MFC como `_AFXDLL` `_AFXEXT` quando os símbolos do pré-processador são definidos. Mas a macro `__declspec(dllimport)` é `_AFXDLL` definida `_AFXEXT` como quando é definida e não é definida. Quando definido, o `_AFXDLL` símbolo do pré-processador indica que a versão compartilhada do MFC está sendo usada pelo executável de destino (uma DLL ou uma aplicação). Quando `_AFXDLL` ambos `_AFXEXT` e são definidos, isso indica que o executável de destino é uma DLL de extensão MFC.

Porque `AFX_EXT_CLASS` é `__declspec(dllexport)` definido como ao exportar a partir de uma dLL de extensão MFC, você pode exportar classes inteiras sem colocar os nomes decorados para todos os símbolos dessa classe no arquivo .def.

Embora você possa evitar criar um arquivo .def e todos os nomes decorados para a classe com este método, criar um arquivo .def é mais eficiente porque os nomes podem ser exportados por ordinal. Para usar o método de exportação do arquivo .def, coloque o seguinte código no início e no final do seu arquivo de cabeçalho:

```cpp
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

> [!CAUTION]
> Tenha cuidado ao exportar funções inline, pois elas podem criar a possibilidade de conflitos de versão. Uma função inline é expandida para o código do aplicativo; portanto, se você reescrever a função mais tarde, ela não será atualizada a menos que o aplicativo em si seja recompilado. Normalmente, as funções dll podem ser atualizadas sem reconstruir os aplicativos que as usam.

## <a name="exporting-individual-members-in-a-class"></a>Exportando membros individuais em uma classe

Às vezes você pode querer exportar membros individuais de sua classe. Por exemplo, se você `CDialog`estiver exportando uma classe derivada, você `DoModal` só pode precisar exportar o construtor e a chamada. Você pode `AFX_EXT_CLASS` usar nos membros individuais que você precisa exportar.

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

Como você não está mais exportando todos os membros da classe, você pode encontrar um problema adicional devido à maneira como as macros MFC funcionam. Várias das macros auxiliares do MFC realmente declaram ou definem membros de dados. Portanto, esses membros de dados também devem ser exportados de sua DLL.

Por exemplo, `DECLARE_DYNAMIC` a macro é definida da seguinte forma ao construir uma DLL de extensão MFC:

```cpp
#define DECLARE_DYNAMIC(class_name) \
protected: \
   static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
   static AFX_DATA CRuntimeClass class##class_name; \
   virtual CRuntimeClass* GetRuntimeClass() const; \
```

A linha que `AFX_DATA` começa com estática é declarar um objeto estático dentro de sua classe. Para exportar esta classe corretamente e acessar as informações de tempo de execução de um executável cliente, você deve exportar este objeto estático. Como o objeto estático é `AFX_DATA`declarado com o `AFX_DATA` modificador, você só precisa definir como ser `__declspec(dllexport)` ao construir sua DLL e defini-lo como `__declspec(dllimport)` ao construir o executável do seu cliente. Como `AFX_EXT_CLASS` já está definido dessa forma, você `AFX_DATA` só precisa `AFX_EXT_CLASS` redefinir para ser o mesmo que em torno de sua definição de classe.

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

Como o MFC `AFX_DATA` sempre usa o símbolo em itens de dados que define dentro de suas macros, essa técnica funciona para todos esses cenários. Por exemplo, funciona `DECLARE_MESSAGE_MAP`para .

> [!NOTE]
> Se você estiver exportando toda a classe em vez de membros selecionados da classe, os membros de dados estáticos serão automaticamente exportados.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos .def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec(dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar funções C++ para uso em executáveis em linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Funções de exportação C para uso em executáveis c ou c++-ling](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](run-time-library-behavior.md#initializing-a-dll)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](reference/decorated-names.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
