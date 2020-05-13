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

As [DLLs de extensão do MFC](extension-dlls-overview.md) usam a macro **AFX_EXT_CLASS** para exportar classes; os executáveis que vinculam à DLL de extensão do MFC usam a macro para importar classes. Com a macro **AFX_EXT_CLASS** , os mesmos arquivos de cabeçalho usados para criar a DLL de extensão MFC podem ser usados com os executáveis vinculados à dll.

No arquivo de cabeçalho para sua DLL, adicione a palavra-chave **AFX_EXT_CLASS** à declaração de sua classe da seguinte maneira:

```cpp
class AFX_EXT_CLASS CMyClass : public CDocument
{
// <body of class>
};
```

Essa macro é definida pelo MFC como `__declspec(dllexport)` quando os símbolos `_AFXDLL` de pré-processador e `_AFXEXT` são definidos. Mas a macro é definida como `__declspec(dllimport)` quando `_AFXDLL` é definida e `_AFXEXT` não é definida. Quando definido, o símbolo `_AFXDLL` de pré-processador indica que a versão compartilhada do MFC está sendo usada pelo executável de destino (uma DLL ou um aplicativo). Quando ambos `_AFXDLL` e `_AFXEXT` são definidos, isso indica que o executável de destino é uma DLL de extensão do MFC.

Como `AFX_EXT_CLASS` o é definido `__declspec(dllexport)` como ao exportar de uma DLL de extensão do MFC, você pode exportar classes inteiras sem colocar os nomes decorados para todos os símbolos dessa classe no arquivo. def.

Embora você possa evitar a criação de um arquivo. def e de todos os nomes decorados para a classe com esse método, a criação de um arquivo. def é mais eficiente, pois os nomes podem ser exportados por ordinal. Para usar o método de exportação de arquivo. def, coloque o seguinte código no início e no final do arquivo de cabeçalho:

```cpp
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

> [!CAUTION]
> Tenha cuidado ao exportar funções embutidas, pois elas podem criar a possibilidade de conflitos de versão. Uma função embutida é expandida no código do aplicativo; Portanto, se você reescrever posteriormente a função, ela não será atualizada, a menos que o próprio aplicativo seja recompilado. Normalmente, as funções de DLL podem ser atualizadas sem recriar os aplicativos que as utilizam.

## <a name="exporting-individual-members-in-a-class"></a>Exportando membros individuais em uma classe

Às vezes, você pode querer exportar membros individuais de sua classe. Por exemplo, se você estiver exportando uma classe derivada de uma `CDialog`, talvez seja necessário apenas exportar o construtor `DoModal` e a chamada. Você pode usar `AFX_EXT_CLASS` o em membros individuais que precisa exportar.

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

Como você não está mais exportando todos os membros da classe, poderá encontrar um problema adicional devido à forma como as macros do MFC funcionam. Várias macros auxiliares do MFC, na verdade, declaram ou definem membros de dados. Portanto, esses membros de dados também devem ser exportados de sua DLL.

Por exemplo, a `DECLARE_DYNAMIC` macro é definida da seguinte maneira ao criar uma DLL de extensão do MFC:

```cpp
#define DECLARE_DYNAMIC(class_name) \
protected: \
   static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
   static AFX_DATA CRuntimeClass class##class_name; \
   virtual CRuntimeClass* GetRuntimeClass() const; \
```

A linha que começa com estático `AFX_DATA` está declarando um objeto estático dentro de sua classe. Para exportar essa classe corretamente e acessar as informações de tempo de execução de um executável do cliente, você deve exportar esse objeto estático. Como o objeto estático é declarado `AFX_DATA`com o modificador, você só precisa definir `AFX_DATA` para ser `__declspec(dllexport)` ao compilar sua dll e defini-la `__declspec(dllimport)` como ao criar o executável do cliente. Como `AFX_EXT_CLASS` já está definido dessa forma, você só precisa redefinir `AFX_DATA` para ser o mesmo que `AFX_EXT_CLASS` em sua definição de classe.

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

Como o MFC sempre usa `AFX_DATA` o símbolo em itens de dados que ele define em suas macros, essa técnica funciona para todos esses cenários. Por exemplo, ele funciona para `DECLARE_MESSAGE_MAP`o.

> [!NOTE]
> Se você estiver exportando toda a classe em vez de membros selecionados da classe, os membros de dados estáticos serão exportados automaticamente.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar funções C++ para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções C para uso em executáveis de linguagem C ou C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](reference/decorated-names.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
