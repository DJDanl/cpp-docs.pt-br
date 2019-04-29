---
title: Importações mútuas
ms.date: 11/04/2016
helpviewer_keywords:
- mutual DLL imports [C++]
- AFX_DATA
- importing DLLs [C++], mutual imports
- mutually importing executable files [C++]
- AFX_EXT_CLASS macro
- circular imports
- _AFXEXT preprocessor symbol
- DLLs [C++], importing
- executable files [C++], importing
- extension DLLs [C++], mutual imports
- exporting DLLs [C++], mutual imports
ms.assetid: 2cc29537-92ee-4d92-af39-8b8b3afd808f
ms.openlocfilehash: f01e69138a6ca1744645a1c2fa8525b7088e260d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62295662"
---
# <a name="mutual-imports"></a>Importações mútuas

Exportar ou importar em outro arquivo executável apresenta complicações quando as importações são mútua (ou circular). Por exemplo, duas DLLs importar símbolos uns dos outros, semelhante a funções mutuamente recursivas.

O problema mutuamente importando arquivos executáveis (normalmente DLLs) é que não podem ser criados sem a criação de outro primeiro. Cada processo de compilação requer, como entrada, uma biblioteca de importação produzida pelo processo de compilação.

A solução é usar o utilitário LIB com a opção /DEF, que produz uma biblioteca de importação sem compilar o arquivo executável. Com esse utilitário, você pode criar todas as bibliotecas de importação, você precisa, não importa quantas DLLs envolvidas ou complicada como as dependências estão.

A solução geral para lidar com Importações mútuas é:

1. Levar cada DLL por vez. (Nenhuma ordem é viável, embora alguns pedidos são melhores.) Se todas as bibliotecas de importação necessários existem e são atuais, execute o LINK para compilar o arquivo executável (DLL). Isso produz uma biblioteca de importação. Caso contrário, execute LIB para produzir uma biblioteca de importação.

   Executando LIB com a opção /DEF produz um arquivo adicional com um. Extensão EXP. A. Arquivos EXP devem ser usado posteriormente para criar o arquivo executável.

1. Depois de usar o LINK ou LIB para compilar todas as bibliotecas de importação, volte e execute o LINK para compilar todos os arquivos executáveis que não foram criados na etapa anterior. Observe que o arquivo. EXP correspondente deve ser especificado na linha de LINK.

   Se você tivesse executado o utilitário LIB anteriormente para produzir uma biblioteca de importação para DLL1, LIB deve ter produzido o arquivo DLL1.exp também. Você deve usar DLL1.exp como entrada para o LINK ao criar DLL1.dlll.

A ilustração a seguir mostra uma solução para duas DLLs mutuamente importação, DLL1 e DLL2. Etapa 1 é executar LIB, com a opção /DEF definida, em DLL1. Etapa 1 produz DLL1.lib, uma biblioteca de importação e DLL1.exp. Na etapa 2, a biblioteca de importação é usada para compilar DLL2, que por sua vez, produz uma biblioteca de importação de símbolos do DLL2. Etapa 3 compila DLL1, usando DLL1.exp e DLL2.lib como entrada. Observe que um arquivo. EXP para DLL2 não é necessário porque LIB não foi usado para criar a biblioteca de importação do DLL2.

![Usar Importações mútuas para vincular duas DLLs](media/vc37yj1.gif "usando Importações mútuas para vincular duas DLLs")<br/>
Vinculando as duas DLLs com Importações mútuas

## <a name="limitations-of-afxext"></a>Limitações de _AFXEXT

Você pode usar o `_AFXEXT` símbolo do pré-processador para a sua extensão MFC DLLs, desde que você não tenha várias camadas de DLLs de extensão do MFC. Se você tiver a extensão de MFC que chame ou derivar de classes em sua própria extensão MFC DLLs, que derivam, em seguida, as classes MFC, você deve usar seu próprio símbolo do pré-processador para evitar ambiguidade.

O problema é que no Win32, você deve declarar explicitamente todos os dados como **dllexport** se ele deve ser exportada de uma DLL, e **__declspec(dllimport)** se for a serem importados de uma DLL. Quando você define `_AFXEXT`, os cabeçalhos MFC ter certeza de que **AFX_EXT_CLASS** está definido corretamente.

Quando você tem várias camadas, um símbolo, como **AFX_EXT_CLASS** não é suficiente, porque uma DLL de extensão do MFC pode ser exportando novas classes bem como importar outras classes de outra extensão MFC DLL. Para resolver esse problema, use um símbolo do pré-processador especial que indica que você está criando a DLL em vez de usar a DLL. Por exemplo, imagine que duas DLLs de extensão do MFC,. dll e b. dll. Cada um deles exportar algumas classes no A.h e B.h, respectivamente. B. dll usa as classes da dll. Os arquivos de cabeçalho seria algo parecido com isto:

```
/* A.H */
#ifdef A_IMPL
   #define CLASS_DECL_A   __declspec(dllexport)
#else
   #define CLASS_DECL_A   __declspec(dllimport)
#endif

class CLASS_DECL_A CExampleA : public CObject
{ ... class definition ... };

// B.H
#ifdef B_IMPL
   #define CLASS_DECL_B   __declspec(dllexport)
#else
   #define CLASS_DECL_B   __declspec(dllimport)
#endif

class CLASS_DECL_B CExampleB : public CExampleA
{ ... class definition ... };
...
```

Quando é compilado. dll, ele é compilado com `/D A_IMPL` e quando b. dll é compilado, ele é compilado com `/D B_IMPL`. Usando símbolos separados para cada DLL `CExampleB` é exportado e `CExampleA` é importado durante a criação de b. dll. `CExampleA` é exportado ao compilar a dll e importado quando usado por b. dll (ou outro cliente).

Esse tipo de disposição em camadas não pode ser feito ao usar o interno **AFX_EXT_CLASS** e `_AFXEXT` símbolos do pré-processador. A técnica descrita acima resolve esse problema de maneira diferente não que o mecanismo próprio MFC usa ao criar suas tecnologias de Active Directory, banco de dados e DLLs de extensão do MFC de rede.

## <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira

Quando você não estiver exportando uma classe inteira, você precisará garantir que os itens de dados necessários criados pelas macros MFC são exportados corretamente. Isso pode ser feito redefinindo `AFX_DATA` para macro da sua classe específica. Isso deve ser feito a qualquer momento que você não estiver exportando a classe inteira.

Por exemplo:

```
/* A.H */
#ifdef A_IMPL
   #define CLASS_DECL_A  _declspec(dllexport)
#else
   #define CLASS_DECL_A  _declspec(dllimport)
#endif

#undef  AFX_DATA
#define AFX_DATA CLASS_DECL_A

class CExampleA : public CObject
{
   DECLARE_DYNAMIC()
   CLASS_DECL_A int SomeFunction();
   //... class definition ...
};

#undef AFX_DATA
#define AFX_DATA
```

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportação de uma DLL](exporting-from-a-dll.md)

- [Exportar de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [O utilitário LIB e a opção /DEF](reference/lib-reference.md)

## <a name="see-also"></a>Consulte também

[Importando e exportando](importing-and-exporting.md)
