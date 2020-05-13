---
title: Projeto de C++ de exemplo para análise de código
description: Como criar uma solução de exemplo para uso no passo a passo de análise de código para o Microsoft C++ no Visual Studio.
ms.date: 04/14/2020
ms.topic: sample
helpviewer_keywords:
- demo sample [Visual Studio ALM]
- code analysis, samples
ms.assetid: 09e1b9f7-5916-4ed6-a001-5c2d7e710682
ms.openlocfilehash: c2a1b8c80b7e7aebd1f1530c66ade5859b392028
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372057"
---
# <a name="sample-c-project-for-code-analysis"></a>Projeto de C++ de exemplo para análise de código

Os procedimentos a seguir mostram como criar a amostra para [o passo a passo: analise o código C/C++ para se há defeitos](../code-quality/walkthrough-analyzing-c-cpp-code-for-defects.md). Os procedimentos criam:

- Uma solução do Visual Studio chamada *CppDemo*.

- Um projeto de biblioteca estática chamado *CodeDefects*.

- Um projeto de biblioteca estática chamado *Anotações*.

Os procedimentos também fornecem o código para o cabeçalho e arquivos *.cpp* para as bibliotecas estáticas.

## <a name="create-the-cppdemo-solution-and-the-codedefects-project"></a>Criar a solução CppDemo e o projeto CodeDefects

::: moniker range=">=vs-2019"

1. Abra o Visual Studio e selecione **Criar um novo projeto**

1. No **Criar um novo diálogo** de projeto, altere o filtro de idioma para **C++**.

1. Selecione **o Assistente de Área de Trabalho do Windows** e escolha o botão **Seguinte.**

1. Na **página Configurar sua nova** página de projeto, na caixa de texto nome do **Projeto,** digite *'Deserdos de código*' .

1. Na caixa de texto **nome da solução,** digite *CppDemo*.

1. Escolha **Criar**.

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** altere o **tipo de aplicativo** para Biblioteca **Estática (.lib)**.

1. Em **opções adicionais,** **selecione Projeto Vazio**.

1. Escolha **OK** para criar a solução e o projeto.

::: moniker-end

::: moniker range="vs-2017"

1. Abra o Visual Studio. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** selecione **Visual C++** > **Windows Desktop**.

1. Selecione **o Assistente de Desktop do Windows**.

1. Na caixa de texto **Nome,** digite *CodeDefects*.

1. Na caixa de texto **nome da solução,** digite *CppDemo*.

1. Escolha **OK**.

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** altere o **tipo de aplicativo** para Biblioteca **Estática (.lib)**.

1. Em **opções adicionais,** **selecione Projeto Vazio**.

1. Escolha **OK** para criar a solução e o projeto.

::: moniker-end

::: moniker range="vs-2015"

1. Abra o Visual Studio. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** selecione **Modelos** > **Visuais C++** > **Win32**.

1. Selecione **o aplicativo de console Win32**.

1. Na caixa de texto **Nome,** digite *CodeDefects*.

1. Na caixa de texto **nome da solução,** digite *CppDemo*.

1. Escolha **OK**.

1. Na caixa de diálogo **Assistente do aplicativo Win32,** escolha o botão **Seguinte.**

1. Alterar o **tipo de aplicativo** para biblioteca **estática**.

1. Em **opções adicionais,** desmarque **cabeçalho pré-compilado**.

1. Escolha **Terminar** para criar a solução e o projeto.

::: moniker-end

## <a name="add-the-header-and-source-file-to-the-codedefects-project"></a>Adicionar o arquivo de cabeçalho e o código-fonte ao projeto CodeDefects

1. No Solution Explorer, expanda **CodeDefects**.

1. Clique com o botão direito do mouse para abrir o menu de contexto de **Arquivos de cabeçalho**. Escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Código Visual C++** > **Code**e selecione Arquivo **de cabeçalho (.h)**.

1. Na caixa de edição **Nome,** digite *Bug.h*e escolha o botão **Adicionar.**

1. Na janela de edição de *Bug.h,* selecione e exclua o conteúdo.

1. Copie o seguinte código e cole-o no arquivo *Bug.h* no editor.

    ```cpp
    #pragma once

    #include <windows.h>

    // Function prototypes
    bool CheckDomain(wchar_t const *);
    HRESULT ReadUserAccount();

    // These constants define the common sizes of the
    // user account information throughout the program
    const int USER_ACCOUNT_LEN = 256;
    const int ACCOUNT_DOMAIN_LEN = 128;
    ```

1. No Solution Explorer, clique com o botão direito do mouse para abrir o menu de contexto para **Arquivos de Origem**. Escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**.

1. Na caixa de edição **Nome,** digite *Bug.cpp*e escolha o botão **Adicionar.**

1. Copie o seguinte código e cole-o no arquivo *Bug.cpp* no editor.

    ```cpp
    #include "Bug.h"

    // the user account
    wchar_t g_userAccount[USER_ACCOUNT_LEN] = { L"domain\\user" };
    int len = 0;

    bool CheckDomain(wchar_t const* domain)
    {
        return (wcsnlen_s(domain, USER_ACCOUNT_LEN) > 0);
    }

    HRESULT ReadUserAccount()
    {
        return S_OK;
    }

    bool ProcessDomain()
    {
        wchar_t* domain = new wchar_t[ACCOUNT_DOMAIN_LEN];
        // ReadUserAccount gets a 'domain\user' input from
        //the user into the global 'g_userAccount'
        if (ReadUserAccount())
        {
            // Copies part of the string prior to the '\'
            // character onto the 'domain' buffer
            for (len = 0; (len < ACCOUNT_DOMAIN_LEN) && (g_userAccount[len] != L'\0'); len++)
            {
                if (g_userAccount[len] == L'\\')
                {
                    // Stops copying on the domain and user separator ('\')
                    break;
                }
                domain[len] = g_userAccount[len];
            }
            if ((len = ACCOUNT_DOMAIN_LEN) || (g_userAccount[len] != L'\\'))
            {
                // '\' was not found. Invalid domain\user string.
                delete[] domain;
                return false;
            }
            else
            {
                domain[len] = L'\0';
            }
            // Process domain string
            bool result = CheckDomain(domain);

            delete[] domain;
            return result;
        }
        return false;
    }

    int path_dependent(int n)
    {
        int i;
        int j;
        if (n == 0)
            i = 1;
        else
            j = 1;
        return i + j;
    }
    ```

1. Na barra de menu, escolha **'Salvar todos'** **do arquivo** > .

## <a name="add-the-annotations-project-and-configure-it-as-a-static-library"></a>Adicionar o projeto Anotações e configurá-lo como uma biblioteca estática

::: moniker range=">=vs-2019"

1. No Solution Explorer, clique com o botão direito do mouse **Em CppDemo** para abrir o menu de contexto. Escolha **adicionar** > **novo projeto**.

1. Na caixa de diálogo Adicionar uma nova caixa de diálogo **de projeto,** selecione **O Assistente de Área de Trabalho do Windows**e escolha o botão **Seguinte.**

1. Na **página Configurar sua nova** página de projeto, na caixa de texto nome do **Projeto,** digite *Anotações*e, em seguida, escolha **Criar**.

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** altere o **tipo de aplicativo** para Biblioteca **Estática (.lib)**.

1. Em **opções adicionais,** **selecione Projeto Vazio**.

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2017"

1. No Solution Explorer, clique com o botão direito do mouse **Em CppDemo** para abrir o menu de contexto. Escolha **adicionar** > **novo projeto**.

1. Na caixa de diálogo **Adicionar novo projeto,** selecione Visual **C++** > **Windows Desktop**.

1. Selecione **o Assistente de Desktop do Windows**.

1. Na caixa de texto **Nome,** *digite Anotações*e escolha **OK**.

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** altere o **tipo de aplicativo** para Biblioteca **Estática (.lib)**.

1. Em **opções adicionais,** **selecione Projeto Vazio**.

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="vs-2015"

1. No Solution Explorer, clique com o botão direito do mouse **Em CppDemo** para abrir o menu de contexto. Escolha **adicionar** > **novo projeto**.

1. Na caixa de diálogo **Adicionar novo projeto,** selecione **Visual C++** > **Win32**.

1. Selecione **o aplicativo de console Win32**.

1. Na caixa de texto **Nome,** *digite Anotações*.

1. Escolha **OK**.

1. Na caixa de diálogo **Assistente do aplicativo Win32,** escolha o botão **Seguinte.**

1. Alterar o **tipo de aplicativo** para biblioteca **estática**.

1. Em **opções adicionais,** desmarque **cabeçalho pré-compilado**.

1. Escolha **Terminar** para criar o projeto.

::: moniker-end

## <a name="add-the-header-file-and-source-file-to-the-annotations-project"></a>Adicionar o arquivo de cabeçalho e o arquivo de origem ao projeto Anotações

1. No Solution Explorer, expanda **as anotações**.

1. Clique com o botão direito do mouse para abrir o menu de contexto de **Arquivos de cabeçalho** em **Anotações**. Escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Código Visual C++** > **Code**e selecione Arquivo **de cabeçalho (.h)**.

1. Na caixa de edição **Nome,** digite *anotações.h*e escolha o botão **Adicionar.**

1. Na janela de edição para *anotações.h,* selecione e exclua o conteúdo.

1. Copie o seguinte código e cole-o no arquivo *anotações.h* no editor.

    ```cpp
    #pragma once
    #include <sal.h>

    struct LinkedList
    {
        struct LinkedList* next;
        int data;
    };

    typedef struct LinkedList LinkedList;

    _Ret_maybenull_ LinkedList* AllocateNode();
    ```

1. No Solution Explorer, clique com o botão direito do mouse para abrir o menu de contexto para **Arquivos de Origem** em **Anotações**. Escolha **Adicionar** > **novo item**.

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**.

1. Na caixa de edição **Nome,** digite *anotações.cpp*e escolha o botão **Adicionar.**

1. Copie o seguinte código e cole-o no arquivo *anotações.cpp* no editor.

    ```cpp
    #include "annotations.h"
    #include <malloc.h>

    _Ret_maybenull_ LinkedList* AllocateNode()
    {
        LinkedList* result = static_cast<LinkedList*>(malloc(sizeof(LinkedList)));
        return result;
    }

    LinkedList* AddTail(LinkedList* node, int value)
    {
        // finds the last node
        while (node->next != nullptr)
        {
            node = node->next;
        }

        // appends the new node
        LinkedList* newNode = AllocateNode();
        newNode->data = value;
        newNode->next = 0;
        node->next = newNode;

        return newNode;
    }
    ```

1. Na barra de menu, escolha **'Salvar todos'** **do arquivo** > .

A solução está agora completa e deve ser construída sem erros.

::: moniker range="vs-2017"

> [!NOTE]
> No Visual Studio 2017, você pode ver `E1097 unknown attribute "no_init_all"` um aviso espúrio no motor IntelliSense. Ignore esse erro.

::: moniker-end
