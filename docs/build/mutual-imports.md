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

Exportar ou importar para outro arquivo executável apresenta complicações quando as importações são mútuas (ou circulares). Por exemplo, duas DLLs importam símbolos umas das outras, semelhante às funções recursivas mutuamente.

O problema com a importação mútua de arquivos executáveis (geralmente DLLs) é que nenhum deles pode ser compilado sem a criação do outro primeiro. Cada processo de compilação requer, como entrada, uma biblioteca de importação produzida pelo outro processo de compilação.

A solução é usar o utilitário LIB com a opção/DEF, que produz uma biblioteca de importação sem compilar o arquivo executável. Usando esse utilitário, você pode criar todas as bibliotecas de importação de que precisa, independentemente de quantas DLLs estão envolvidas ou da complexidade das dependências.

A solução geral para lidar com importações mútuas é:

1. Use cada DLL por vez. (Qualquer ordem é viável, embora alguns pedidos sejam mais ideais.) Se todas as bibliotecas de importação necessárias existirem e estiverem atuais, execute o LINK para compilar o arquivo executável (DLL). Isso produz uma biblioteca de importação. Caso contrário, execute LIB para produzir uma biblioteca de importação.

   A execução de LIB com a opção/DEF produz um arquivo adicional com um. Extensão de EXP. Dos. O arquivo EXP deve ser usado posteriormente para criar o arquivo executável.

1. Depois de usar o LINK ou a LIB para compilar todas as bibliotecas de importação, volte e execute o LINK para compilar os arquivos executáveis que não foram criados na etapa anterior. Observe que o arquivo. exp correspondente deve ser especificado na linha de LINK.

   Se você tiver executado o utilitário LIB anteriormente para produzir uma biblioteca de importação para DLL1, LIB teria produzido o arquivo DLL1. exp também. Você deve usar DLL1. exp como entrada para vincular ao compilar DLL1. dlll.

A ilustração a seguir mostra uma solução para duas DLLs de importação mútua, DLL1 e DLL2. A etapa 1 é executar LIB, com a opção/DEF definida, em DLL1. A etapa 1 produz DLL1. lib, uma biblioteca de importação e DLL1. exp. Na etapa 2, a biblioteca de importação é usada para criar DLL2, que, por sua vez, produz uma biblioteca de importação para símbolos DLL2's. A etapa 3 cria DLL1, usando DLL1. exp e DLL2. lib como entrada. Observe que um arquivo. exp para DLL2 não é necessário porque a LIB não foi usada para compilar a biblioteca de importação DLL2's.

![Usando importações mútuas para vincular duas DLLs](media/vc37yj1.gif "usando importações mútuas para vincular duas DLLs")<br/>
Vinculando duas DLLs com importações mútuas

## <a name="limitations-of-_afxext"></a>Limitações de _AFXEXT

Você pode usar o `_AFXEXT` símbolo de pré-processador para as DLLs de extensão do MFC, desde que você não tenha várias camadas de DLLs de extensão do MFC. Se você tiver DLLs de extensão do MFC que chamam ou derivam de classes em suas próprias DLLs de extensão do MFC, que derivam das classes do MFC, você deve usar seu próprio símbolo de pré-processador para evitar ambigüidade.

O problema é que, no Win32, você deve declarar explicitamente quaisquer dados como **__declspec (dllexport)** se ele for exportado de uma dll e **__declspec (dllimport)** se for para ser importado de uma dll. Quando você define `_AFXEXT`, os cabeçalhos do MFC verificam se **AFX_EXT_CLASS** está definido corretamente.

Quando você tem várias camadas, um símbolo como **AFX_EXT_CLASS** não é suficiente, porque uma DLL de extensão do MFC pode estar exportando novas classes, bem como importando outras classes de outra DLL de extensão do MFC. Para resolver esse problema, use um símbolo de pré-processador especial que indica que você está criando a DLL em si versus usando a DLL. Por exemplo, imagine duas DLLs de extensão MFC, uma. dll e B. dll. Cada uma delas exporta algumas classes em A. h e B. h, respectivamente. B. dll usa as classes de uma. dll. Os arquivos de cabeçalho teriam uma aparência semelhante a esta:

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

Quando um. dll é criado, ele é criado com `/D A_IMPL` e quando B. dll é criado, ele é criado com `/D B_IMPL`. O uso de símbolos separados para cada DLL `CExampleB` é exportado e importado durante a criação de `CExampleA` B. dll. `CExampleA`é exportada ao criar uma. dll e importada quando usada pela B. dll (ou algum outro cliente).

Esse tipo de disposição em camadas não pode ser feito ao usar os símbolos **AFX_EXT_CLASS** internos de `_AFXEXT` AFX_EXT_CLASS e de pré-processador. A técnica descrita acima resolve esse problema de uma maneira que não é diferente do próprio mecanismo que o MFC usa durante a criação de suas tecnologias ativas, banco de dados e DLLs de extensão do MFC de rede.

## <a name="not-exporting-the-entire-class"></a>Não exportando toda a classe

Quando você não estiver exportando uma classe inteira, precisará garantir que os itens de dados necessários criados pelas macros do MFC sejam exportados corretamente. Isso pode ser feito pela redefinição `AFX_DATA` para a macro de sua classe específica. Isso deve ser feito sempre que você não estiver exportando a classe inteira.

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

- [Exportar de uma DLL](exporting-from-a-dll.md)

- [Exportar de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [O utilitário LIB e a opção/DEF](reference/lib-reference.md)

## <a name="see-also"></a>Confira também

[Importando e exportando](importing-and-exporting.md)
